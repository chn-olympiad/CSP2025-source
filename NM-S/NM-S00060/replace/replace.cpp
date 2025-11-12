#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(x, y, z) for(ll x = y; x <= z; x++)
const ll INF = 0x3f3f3f3f3f3f3f3f, N = 2e5 + 10, BASE = 13, P = 1e9 + 7, BASE2 = 7;
ll n, q;
map<array<ll, 3>, ll> a;

string s, t;
void calc(string&s, string&t)
{
	if(s == t) return;
	ll bg = -1, ed = 0;
	f(i, 0, s.size() - 1) if(s[i] != t[i])
	{
		if(bg == -1) bg = i;
		ed = i;
	}
//	f(i, bg, ed) ss.push_back(s[i]), tt.push_back(t[i]);
//	cerr<<bg<<", "<<ed<<endl;
	s.insert(s.begin() + bg, '#');
	s.insert(s.begin() + ed, '#');
//	swap(s, ss), swap(t, tt);
}
ll mk(const string& s, const ll BASE = ::BASE)
{
	ll res = 0;
	for(auto c : s)
	{
		res = res * BASE % P;
		res += c;
		res %= P;
	}
	return res;
}

//const pair<string, string> ttt= {"uyucqryhrjmrrcmfastozgdyvnnejyokornvimwzaijuqsienpfofktwhydvztgxpavjrp", "nhvarpmcurogqsjnsymlzdmvilobyooplzkfvkhegxzrvcygauplfuyfkyakftyyxdsdsw"};
signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	f(i, 1, n)
	{
		cin >> s >> t;
		calc(s, t);
//		a[{mk(ss), mk(tt)}] ++;
		a[{mk(s), mk(t), mk(s, BASE2)}] ++;
		/*pair<string, string >sss = {s, t};
		if(sss == ttt) cerr<<i<<" aaaaaa"<<endl;
		if(i == 101) return 0;
		if(a[ttt] == 360)
		{
			cerr<<i<<endl;
			cerr<<s<<endl<<t<<endl;
			cerr<<endl<<endl;
			return 0;
		}
//		if({s, t} == (pair<string, string>)) cerr<<i<<endl;*/
	}

	f(i, 1, q)
	{
		cin >> s >> t;
//		if(i == 101) cerr<< s<<endl<<endl<<t<<endl;
		calc(s, t);
//		if(i == 101) cerr<< s<<endl<<endl<<t<<endl;
		const auto& it = a.find({mk(s), mk(t), mk(s, BASE2)});
		if(it == a.end()) cout << 0 << endl;
		else cout << (it -> second) << endl;
//		if(i == 101) cerr<<endl<<endl<<it -> first.first<<endl<<it -> first.second<<endl<<(it -> second);
	}
	return 0;
}

/*
注意替换只能进行一次

把询问的最靠前和最靠后的差异位置找到

需要找到以 t 为字串的对的前向，同时对应位置的哈希也有用

这怎么搞

要么是吧询问离线然后对n各队拍类AC自动机

要么是哈希加根号分支

哦，先在询问的这个对应的区间内随机一个位置，找一下满足对应关系的

先按差异子串把询问和条件分类

把外面的截掉

求一下哈希是不是就做完了

糖糖糖

16：20
*/
