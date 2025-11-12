#include<bits/stdc++.h>
using namespace std;
int T,n,d1[100005],d2[100005],d3[100005],x,y,z,ans,Ax,Ay,Az;
int main()
{
	cin>>T;
	while(--T)
	{
		cin>>n;
		memset(d1,0,sizeof(d1));
		memset(d2,0,sizeof(d2));
		memset(d3,0,sizeof(d3));
		Ax=0,Ay=0,Az=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x>>y>>z;
			if(x>=y&&x>=z) Ax++,d1[Ax]=min(x-y,x-z),ans+=x;
			else if(y>=x&&y>=z) Ay++,d2[Ay]=min(y-x,y-z),ans+=y;
			else Az++,d3[Az]=min(z-x,z-y),ans+=z;
		}
		if(Ax>n/2)
		{
			sort(d1+1,d1+Ax+1);
			for(int i=1;i<=n/2-Ax;i++) ans=-d1[i];
		}
		if(Ay>n/2)
		{
			sort(d2+1,d2+Ay+1);
			for(int i=1;i<=n/2-Ay;i++) ans=-d2[i];
		}
		if(Az>n/2)
		{
			sort(d3+1,d3+Az+1);
			for(int i=1;i<=n/2-Az;i++) ans-d3[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
