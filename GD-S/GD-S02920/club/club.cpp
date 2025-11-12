#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,tool[MAXN],ans=0;
struct Each
{
	int f[3];
}a[MAXN];
void solve(int p)
{
	for(int i=1;i<=3;i++)
	{
		tool[p]=i;
		int cnt[4],N=(n>>1),x=0;
		for(int i=1;i<=3;i++)
			cnt[i]=0;
		for(int i=1;i<=p;i++)
		{
			cnt[tool[i]]++;
			if(cnt[1]>N||cnt[2]>N||cnt[3]>N)
			{
				x=1;
				break;
			}
		}
		if(x)
			continue;
		if(p<n)
		{
			solve(p+1);
			continue;
		}
		//
//		cout<<endl<<"//cnt: "<<cnt[1]<<" "<<cnt[2]<<" "<<cnt[3]<<endl;
//		for(int i=1;i<=n;i++)
//			cout<<tool[i]<<" ";
//		cout<<endl;
		//
		int res=0;
		for(int i=1;i<=n;i++)
			res+=a[i].f[tool[i]-1];
		ans=max(res,ans);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i].f[0]>>a[i].f[1]>>a[i].f[2];
		ans=0; 
		solve(1);
		cout<<ans<<"\n";
	}
	return 0;
} 

/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
