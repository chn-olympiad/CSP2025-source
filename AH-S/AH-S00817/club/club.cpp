#include<bits/stdc++.h>
using namespace std;
long long T,n,t,ans;
long long a[100005],b[100005],c[100005];
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T)
	{
		cin>>n;
		if(n==2)
		{
			cin>>a[1]>>b[1]>>c[1]>>a[2]>>b[2]>>c[2];
			int maxn=max(max(a[1],b[1]),c[1]),maxn2=max(max(a[2],b[2]),c[2]),maxt,maxt2;
			if(maxn==a[1]) maxt=1;
			else if(maxn==b[1]) maxt=2;
			else maxt=3;
			
			if(maxn==a[2]) maxt2=1;
			else if(maxn==b[2]) maxt2=2;
			else maxt2=3;
			
			if(maxt==maxt2)
			{
				if(maxt==1)
				{
					long long t,t2,t3,t4;
					t=maxn-b[1]; t2=maxn-c[1]; t3=maxn2-b[2]; t4=maxn2-c[2];
					int minn=min(t,min(t2,min(t3,t4)));
					cout<<maxn+maxn2-minn<<'\n';
				}
				if(maxt==2)
				{
					long long t,t2,t3,t4;
					t=maxn-a[1]; t2=maxn-c[1]; t3=maxn2-a[2]; t4=maxn2-c[2];
					int minn=min(t,min(t2,min(t3,t4)));
					cout<<maxn+maxn2-minn<<'\n';
				}
				if(maxt==3)
				{
					long long t,t2,t3,t4;
					t=maxn-a[1]; t2=maxn-b[1]; t3=maxn2-a[2]; t4=maxn2-b[2];
					int minn=min(t,min(t2,min(t3,t4)));
					cout<<maxn+maxn2-minn<<'\n';
				}
			}
			else cout<<maxn+maxn2<<'\n';
		}
		else
		{
			for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++) ans+=a[i];
			cout<<ans<<'\n';
		}
		T--;
	}
	
}
