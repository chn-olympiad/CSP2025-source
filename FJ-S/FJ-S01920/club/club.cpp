#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define fi first
#define se second
#define ms(a,b) memset(a,b,sizeof(a))
#define lowbit(x) x&(-x)
#define mk make_pair


inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while(ch >'9' || ch < '0')
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x<<1) + (x<<3) + (ch^48);
		ch = getchar();
	}
	return x*f;
}

int T;
int n;
int a[100010][3];
pair<int,int> b[100010][2];
int s[3];

struct nod
{
	int id, cha;
};
vector<nod> f[3];

inline bool cmp(nod u, nod v)
{
	return u.cha < v.cha;
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T = read();
	while(T--)
	{
		f[0].clear(), f[1].clear(), f[2].clear();
		s[0] = 0, s[1] = 0, s[2] = 0;
		n = read();
		for(int i = 1;i <= n;++i)
		{
			a[i][0] = read(), a[i][1] = read(), a[i][2] = read();
			int id = 0;
			int _id = 0;
			nod t;
			if(a[i][0] >= a[i][1] && a[i][0] >= a[i][2])
			{
				s[0] += a[i][0];
				id = 0;
				if(a[i][1] >= a[i][2]) _id = 1;
				else _id = 2;
			}
			else if(a[i][1] >= a[i][0] && a[i][1] >= a[i][2])
			{
				s[1] += a[i][1];
				id = 1;
				if(a[i][0] >= a[i][2]) _id = 0;
				else _id = 2;
			}
			else
			{
				s[2] += a[i][2];
				id = 2;
				if(a[i][0] >= a[i][1]) _id = 0;
				else _id = 1;
			}
			b[i][0] = (mk(a[i][id],id));
			b[i][1] = (mk(a[i][_id],_id));
			t.id = i;
			t.cha = b[i][0].fi-b[i][1].fi;
			f[id].pb(t);
		}
		int id = -1;
		for(int i = 0;i <= 2;++i)
		{
			if(f[i].size() > (n/2)) id = i;
		}
		int ans = s[0]+s[1]+s[2];
		if(id == -1)
		{
			cout << ans << endl;
			continue;
		}
		sort(f[id].begin(),f[id].end(),cmp);
		int t = 0;
		for(int i = 0;i < f[id].size();++i)
		{
			++t;
			ans -= f[id][i].cha;
			if(f[id].size()-t == (n/2)) break;
		}
		cout << ans << endl;
	}
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
