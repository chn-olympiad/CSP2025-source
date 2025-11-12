#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N][3],ans,f[N];
inline void dfs(int p,int s,int b1,int b2,int b3)
{
	if(p>n)
	{
		ans=max(ans,s);
		return;
	}
	if(f[n]-f[p-1]+s<=ans)
		return;
	if(b1<n/2)dfs(p+1,s+a[p][1],b1+1,b2,b3);
	if(b2<n/2)dfs(p+1,s+a[p][2],b1,b2+1,b3);
	if(b3<n/2)dfs(p+1,s+a[p][3],b1,b2,b3+1);
}
int o[3][N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n<=30)
		{
			for(int i=1;i<=n;i++)
			{
				f[i]=0;
				cin>>a[i][1]>>a[i][2]>>a[i][3];
				f[i]=max(f[i],f[i-1]+max(a[i][2],max(a[i][3],a[i][1])));
			}
			ans=0;
			dfs(1,0,0,0,0);
		}
		else 
		{
			bool f2=true,f3=true;
			for(int i=1;i<=n;i++)
			{
				cin>>o[1][i]>>o[2][i]>>o[3][i];
				if(o[i][2]!=0)
					f2=false;
				if(o[i][3]!=0)
					f3=false;
			}
			if(f2&&f3)
			{
				sort(o[1]+1,o[1]+1+n);
				for(int i=n;i>=n/2;i--)
					ans+=o[1][i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 

