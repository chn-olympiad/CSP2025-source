#include<bits/stdc++.h>
using namespace std;
int T,n,a[100001],b[100001],c[100001],t[100001];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);  
    cin>>T;
    while(T--)
    {
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		cin>>n;
		int maxn=n/2;
		int sum=0,sumb=0,ans=0;
		bool flag1=1,flag2=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(b[i])flag1=0;
			if(c[i])flag2=0;
			sum+=a[i]+b[i]+c[i]; 
			sumb+=b[i];
		}
		if(flag1&&flag2)
		{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=maxn;i++)
			{
				ans+=a[i];
			}
		}
		else if(flag1==0&&flag2==1)
		{
			for(int i=1;i<=n;i++)
			{
				t[i]=a[i]-b[i];
			}
			sort(t+1,t+1+n,cmp);
			ans=sumb;
			for(int i=1;i<=maxn;i++)
			{
				ans+=t[i];
			}
		}
		else if(n==2)
		{
			ans=max((max(a[1]+b[2],b[1]+a[2]),max(a[1]+c[2],c[1]+a[2])),max(b[1]+c[2],c[1]+b[2]));
		}
		else if(n==4)
		{
			int ans1=max(max(max(max(a[1]+a[2]+b[3]+c[4],a[1]+a[2]+c[3]+b[4]),max(a[1]+b[2]+a[3]+c[4],a[1]+c[2]+a[3]+b[4])),max(max(a[1]+b[2]+c[3]+a[4],a[1]+c[2]+b[3]+a[4]),max(b[1]+a[2]+a[3]+c[4],c[1]+a[2]+a[3]+b[4]))),max(max(b[1]+a[2]+c[3]+a[4],c[1]+a[2]+b[3]+a[4]),max(b[1]+c[2]+a[3]+a[4],c[1]+b[2]+a[3]+a[4])));
			
			int ans2=max(max(max(max(b[1]+b[2]+a[3]+c[4],b[1]+b[2]+c[3]+a[4]),max(b[1]+a[2]+b[3]+c[4],b[1]+c[2]+b[3]+a[4])),max(max(b[1]+a[2]+c[3]+b[4],b[1]+c[2]+a[3]+b[4]),max(a[1]+b[2]+b[3]+c[4],c[1]+b[2]+b[3]+a[4]))),max(max(a[1]+b[2]+c[3]+b[4],c[1]+b[2]+a[3]+b[4]),max(a[1]+c[2]+b[3]+b[4],c[1]+a[2]+b[3]+b[4])));
			
			int ans3=max(max(max(max(c[1]+c[2]+a[3]+b[4],c[1]+c[2]+b[3]+a[4]),max(c[1]+a[2]+c[3]+b[4],c[1]+b[2]+c[3]+a[4])),max(max(c[1]+a[2]+b[3]+c[4],c[1]+b[2]+a[3]+c[4]),max(a[1]+c[2]+c[3]+b[4],b[1]+c[2]+c[3]+a[4]))),max(max(a[1]+c[2]+b[3]+c[4],b[1]+c[2]+a[3]+c[4]),max(a[1]+b[2]+c[3]+c[4],b[1]+a[2]+c[3]+c[4])));
			
			int ans4=max(max(max(a[1]+a[2]+b[3]+b[4],b[1]+b[2]+a[3]+a[4]),max(a[1]+b[2]+a[3]+b[4],b[1]+a[2]+b[3]+a[4])),max(a[1]+b[2]+b[3]+a[4],b[1]+a[2]+a[3]+b[4]));
			
			int ans5=max(max(max(c[1]+c[2]+b[3]+b[4],b[1]+b[2]+c[3]+c[4]),max(c[1]+b[2]+c[3]+b[4],b[1]+c[2]+b[3]+c[4])),max(c[1]+b[2]+b[3]+c[4],b[1]+c[2]+c[3]+b[4]));
			
			int ans6=max(max(max(c[1]+c[2]+a[3]+a[4],a[1]+a[2]+c[3]+c[4]),max(c[1]+a[2]+c[3]+a[4],a[1]+c[2]+a[3]+c[4])),max(c[1]+a[2]+a[3]+c[4],a[1]+c[2]+c[3]+a[4]));
			
			ans=max(max(max(ans1,ans2),max(ans3,ans4)),max(ans5,ans6));
		}
		cout<<ans<<endl;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
