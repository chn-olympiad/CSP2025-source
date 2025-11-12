#include<bits/stdc++.h>
using namespace std;
struct node{
	long long d1,d2,d3;
}a[100005];
long long s1,s2,s3;
long long ans;
long long cha[100005]; 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		s1=0;s2=0;s3=0;ans=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld %lld %lld",&a[i].d1,&a[i].d2,&a[i].d3);
			if(a[i].d1>=a[i].d2&&a[i].d1>=a[i].d3)
			{
				s1++;ans+=a[i].d1;
			}
			else if(a[i].d2>=a[i].d1&&a[i].d2>=a[i].d3){
				s2++;ans+=a[i].d2;
			}
			else if(a[i].d3>=a[i].d1&&a[i].d3>=a[i].d2){
				s3++;ans+=a[i].d3;
			}
		}
		if((s1<=n/2)&&(s2<=n/2)&&(s3<=n/2))
		{
			printf("%lld\n",ans);
			continue;
		}
		long long tot=0,op;
		if(s1>n/2)
		{
			op=s1-n/2;
			for(int i=1;i<=n;i++){
				if(a[i].d1>=a[i].d2&&a[i].d1>=a[i].d3){
					tot++;cha[tot]=min(a[i].d1-a[i].d2,a[i].d1-a[i].d3);
				}
			}
		}
		else if(s2>n/2)
		{
			op=s2-n/2;
			for(int i=1;i<=n;i++)
			{
				if(a[i].d2>=a[i].d1&&a[i].d2>=a[i].d3){
					tot++;cha[tot]=min(a[i].d2-a[i].d1,a[i].d2-a[i].d3);
				}
			}
		}
		else if(s3>n/2)
		{
			op=s3-n/2;
			for(int i=1;i<=n;i++)
			{
				if(a[i].d3>=a[i].d1&&a[i].d3>=a[i].d2){
				tot++;cha[tot]=min(a[i].d3-a[i].d1,a[i].d3-a[i].d2);
				}
			}
		}
		sort(cha+1,cha+1+tot);
		for(int i=1;i<=op;i++)
		{
			ans-=cha[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
