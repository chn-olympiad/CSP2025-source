#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long 
#define Blue_Archive return 0
using namespace std;
constexpr int N = 2e5 + 7;
constexpr int P = 1333331;
constexpr int mod = 998244353;

int n;
int q;
ull p[N];
ull ha1[N];
ull ha2[N];

struct miku
{
	string s1,s2;
	int len;
	ull ha1,ha2;
}a[N];

string t1;
string t2;

inline ull get_Hash1(int l,int r)
{
	return ha1[r] - ha1[l - 1] * p[r - l + 1];
}

inline ull get_Hash2(int l,int r)
{
	return ha2[r] - ha2[l - 1] * p[r - l + 1];
}

signed main()
{
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	// freopen("data.in","r",stdin);freopen("data.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> q;
	p[0] = 1;
	for(int i = 1;i < N;i ++) p[i] = p[i - 1] * P;
	for(int i = 1;i <= n;i ++)
	{
		ull ha;
		cin >> a[i].s1 >> a[i].s2;
		a[i].len = a[i].s1.length();
		ha = 0;
		for(int j = 0;j < a[i].len;j ++) ha = ha * P + a[i].s1[j] - 'a' + 1;
		a[i].ha1 = ha;
		ha = 0;
		for(int j = 0;j < a[i].len;j ++) ha = ha * P + a[i].s2[j] - 'a' + 1;
		a[i].ha2 = ha;
	}
	for(int i = 1,len,tot;i <= q;i ++)
	{
		cin >> t1 >> t2;
		tot = 0;
		len = t1.length();
		for(int j = 0;j < len;j ++)
		{
			ha1[j + 1] = ha1[j] * P + t1[j] - 'a' + 1;
			ha2[j + 1] = ha2[j] * P + t2[j] - 'a' + 1;
		}
		int l = 1,r = len,mid,resl = 0,resr = len + 1; // 手搓二分哈希
		while(l <= r)
		{
			mid = (l + r) >> 1;
			if(get_Hash1(1,mid) == get_Hash2(1,mid)) l = mid + 1,resl = mid;
			else r = mid - 1;
		}
		resl ++; // 不同的位置的开始
		l = 1,r = len;
		while(l <= r)
		{
			mid = (l + r) >> 1;
			if(get_Hash1(mid,len) == get_Hash2(mid,len)) r = mid - 1,resr = mid;
			else l = mid + 1;
		}
		resr --; // 不同位置的结束
		// 不同的区间为 [resl,resr]
		for(int k = 1;k <= n;k ++)
		{
			for(int j = 1;j <= resl;j ++) // O(L)
			{
				if(j + a[k].len - 1 < resr || j + a[k].len - 1 > len) continue;
				if(get_Hash1(j,j + a[k].len - 1) == a[k].ha1 && get_Hash2(j,j + a[k].len - 1) == a[k].ha2)
				{
					tot ++;
				}
			}
		}
		cout << tot << '\n';
	}
	Blue_Archive;
}