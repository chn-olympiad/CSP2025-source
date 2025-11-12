#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long t,n,m,a[N][5],q[N][5],maxx[N],s[N],p,ans,m1,m2,m3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		scanf("%lld",&n);
		m=0,ans=0;
		m1=0,m2=0,m3=0;
		memset(q,0,sizeof(q));
		memset(s,0,sizeof(s));
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			q[i][1]=abs(a[i][1]-a[i][2]);
			q[i][2]=abs(a[i][2]-a[i][3]);
			q[i][3]=abs(a[i][1]-a[i][3]);
			if(a[i][1]>=a[i][2] and a[i][1]>=a[i][3]) maxx[i]=1,ans+=a[i][1],m1++;
			if(a[i][2]>a[i][1] and a[i][2]>=a[i][3]) maxx[i]=2,ans+=a[i][2],m2++;
			if(a[i][3]>a[i][1] and a[i][3]>a[i][2]) maxx[i]=3,ans+=a[i][3],m3++;
		}
		if(m1<=n/2 and m2<=n/2 and m3<=n/2) 
		{
			printf("%lld\n",ans);
			continue;
		}
		if(m1>n/2) 
		{
			for(int i=1;i<=n;i++)
				if(maxx[i]==1) s[++m]=min(q[i][1],q[i][3]);
			sort(s+1,s+m+1);
			long long az=m1-n/2;
			for(int i=1;i<=az;i++)
				ans-=s[i];
		}
		if(m2>n/2)
		{
			for(int i=1;i<=n;i++)
				if(maxx[i]==2) s[++m]=min(q[i][1],q[i][2]);
			sort(s+1,s+m+1);
			long long az=m2-n/2;
			for(int i=1;i<=az;i++)
				ans-=s[i];
		}
		if(m3>n/2)
		{
			for(int i=1;i<=n;i++)
				if(maxx[i]==3) s[++m]=min(q[i][2],q[i][3]);
			sort(s+1,s+m+1);
			long long az=m3-n/2;
			for(int i=1;i<=az;i++)
				ans-=s[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
