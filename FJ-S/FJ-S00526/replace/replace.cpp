#include <unordered_map>
#include <iostream>
#include <cstring>

using namespace std;

unordered_map<string,string> mp;
unordered_map<string,bool> flag;

int n,q;

string t1,t2;
string s;
string t;

int len;

int ans = 0;

int limit = 1;

//void dfs(string now,int deep)
//{
//	if (deep >= limit) return;
//	std :: cout << "now:" << now << " " << "\n";
//	if (flag[now]) return;
//	flag[now] = true;
//	if (now == t)
//	{
//		ans ++;
//		return;
//	}
//	for (int l = 0 ; l < len ; l ++)
//	{
//		for (int r = 0 ; r < len ; r ++)
//		{
//			//std :: cout << "substr:" << s.substr(l,r) << "\n";
//			if (mp[s.substr(l,r)] != "")
//			{
//				std :: cout << l << " " << r << " " << s.substr(l,r) << "\n";
//				auto x = s.substr(0,l);
//				auto y = mp[s.substr(l,r)];
//				auto z = s.substr(r + 1,len);
//				//std :: cout << x << " " << y << " " << z << "\n";
//				dfs(x + y + z,deep + 1);
//			}
//		}
//	}
//}

void solve()
{
	std :: cin >> s >> t;
	len = s.length();
	ans = 0;
	//dfs(s,0);
	for (int l = 0 ; l < len ; l ++)
	{
		for (int r = l ; r < len ; r ++)
		{
			string temp;
			for (int i = l ; i <= r ; i ++)
			{
				temp.push_back(s[i]);
			} 
			//std :: cout << temp << "\n";
//			std :: cout << "substr:" << s.substr(l,r) << "\n";
			if (mp[temp] != "")
			{
				//std :: cout << l << " " << r << " " << s.substr(l,r) << "\n";
				string x;
				for (int i = 0 ; i < l ; i ++) x.push_back(s[i]);
				string y = mp[temp];
				string z;
				for (int i = r + 1 ; i < len ; i ++) z.push_back(s[i]);
//				auto x = s.substr(0,l);
//				auto y = mp[s.substr(l,r)];
//				auto z = s.substr(r + 1,len);
				//std :: cout << x << " " << y << " " << z << "\n";
				//std :: cout << "a:" << x << " " << y << " " << z << "\n";
				if (x + y + z == t) ans ++;
			}
		}
	}
	std :: cout << ans << "\n";
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	std :: cin >> n >> q;
	for (int i = 1 ; i <= n ; i ++)
	{
		std :: cin >> t1 >> t2;
		mp[t1] = t2;
	}
	while (q --) solve();
}
