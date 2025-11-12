#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,k;
int a[N],l_[N],r_[N],u=1,cnt=0,ans=0;
void dfs(int c,int p)
{
	for(int i=u;i<=cnt;i++)
	{
		if(l_[i]>p)
		{
			int t=u;
			ans=max(ans,c+1);
			u=i+1;
			dfs(c+1,r_[i]);
			u=t;
		}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	int vp=0,pv=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==1)
		vp++;
		if(a[i]==0)
		pv++;
	}
	if(vp==n&&k==0)
	{
		cout<<n/2<<endl;
		return 0;
	}
	else if(vp+pv==n&&k==1)
	{
		cout<<vp<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int s=0;
		for(int j=i;j<=n;j++)
		{
			s^=a[j];
			if(s==k)
			{
				l_[++cnt]=i;
				r_[cnt]=j;
				break;
			}
		}
	}
	dfs(0,0);
	cout<<ans<<endl;
	return 0;
}
