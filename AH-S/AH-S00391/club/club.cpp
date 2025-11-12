#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int ans = 0;
struct node
{
	int a,b,c;
	int id;
}s[N];
bool f[N];
inline int max_(int u,int v)
{
	return u>v ? u : v;
}
void dfs(int now,int q,int w,int e,int v)
{
	if(now==n+1)
	{
		ans=max(ans,v);
		return ;
	}
	if(q+1 <= n/2) dfs(now+1,q+1,w,e,v+s[now].a);
	if(w+1 <= n/2) dfs(now+1,q,w+1,e,v+s[now].b);
	if(e+1 <= n/2) dfs(now+1,q,w,e+1,v+s[now].c);
	return ;
}
bool cmp1(node u,node v)
{
	return u.a > v.a;
}
bool cmp2(node u,node v)
{
	return u.b > v.b;
}
bool cmp3(node u,node v)
{
	return u.c > v.c;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		ans=0;
		cin >> n;
		for(int i = 1;i<=n;i++)
		{
			f[i]=0;
			cin >> s[i].a >> s[i].b >> s[i].c;
			s[i].id=i;
		}
		//if(n<30)dfs(1,0,0,0,0);
		//else
		//{
			int tmp1=0;
			sort(s+1,s+1+n,cmp1);
			for(int i=1;i<=n;i++)
			{
				if(s[i].b > s[i].a || s[i].c > s[i].a)continue;
				tmp1++;
				f[s[i].id]=1;
				ans+=s[i].a;
				if(tmp1== n/2) break;
			}
			int tmp2=0;
			sort(s+1,s+1+n,cmp2);
			for(int i = 1;i<=n;i++)
			{
				if(s[i].a > s[i].b || s[i].c > s[i].b) continue;
				if(f[s[i].id]) continue;
				tmp2++;
				f[s[i].id]=1;
				ans+=s[i].b;
				if(tmp2==n/2) break;
			}
			int tmp3=0;
			sort(s+1,s+1+n,cmp3);
			for(int i = 1;i<=n;i++)
			{
				if(s[i].a > s[i].c || s[i].b > s[i].c) continue;
				if(f[s[i].id]) continue;
				tmp3++;
				f[s[i].id]=1;
				ans+=s[i].c;
				if(tmp3==n/2) break;
			}
			if(tmp1+tmp2+tmp3 < n)
			{
				sort(s+1,s+1+n,cmp1);
				for(int i = 1;i<=n;i++)
				{
					if(tmp1==n/2) break;
					if(!f[s[i].id])
					{
						ans+=s[i].a;
						tmp1++;
					}
				}
				sort(s+1,s+1+n,cmp2);
				for(int i = 1;i<=n;i++)
				{
					if(tmp2==n/2) break;
					if(!f[s[i].id])
					{
						ans+=s[i].b;
						tmp2++;
					}
				}
				sort(s+1,s+1+n,cmp3);
				for(int i = 1;i<=n;i++)
				{
					if(tmp3==n/2) break;
					if(!f[s[i].id])
					{
						ans+=s[i].c;
						tmp3++;
					}
				}
			}
		//}
		cout << ans << "\n";
	}
	return 0;
}
