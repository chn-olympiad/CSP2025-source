#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005],vis1=1,vis2=1;
int solve(int i,int x,int y,int z,int ans)
{
	int mx=0;
	if(i==n)	return ans;
	if(x<n/2)	mx=max(solve(i+1,x+1,y,z,ans+a[i]),mx);
	if(y<n/2)	mx=max(solve(i+1,x,y+1,z,ans+b[i]),mx);
	if(z<n/2)	mx=max(solve(i+1,x,y,z+1,ans+c[i]),mx);
	return mx;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]>0)	vis1=0;
			if(c[i]>0)	vis2=0;
		}
		if(n<=30)	cout<<solve(0,0,0,0,0)<<"\n";
		else
		{
			int ans=0;
			if(vis1 && vis2)
			{
				sort(a,a+n,greater<int>());
				for(int i=0;i<n/2;i++)	ans+=a[i];
			}
			else
			{
				for(int i=0;i<n;i++)
					ans+=max(a[i],b[i]);
			}
			cout<<ans<<"\n";
		}
	}
	return 0;	
} 
