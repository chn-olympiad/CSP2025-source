//luogu uid:1025129 A club
#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct s
{
	int s1,s2,s3;
}k[100010];
int dp[100010];
bool cmp1(s x,s y)
{
	return (max(x.s1,max(x.s2,x.s3))==x.s1&&max(y.s1,max(y.s2,y.s3))!=y.s1)||((max(x.s1,max(x.s2,x.s3))==x.s1&&max(y.s1,max(y.s2,y.s3))==y.s1)&&x.s1-max(x.s2,x.s3)<y.s1-max(y.s2,y.s3));
}
bool cmp2(s x,s y)
{
	return (max(x.s1,max(x.s2,x.s3))==x.s2&&max(y.s1,max(y.s2,y.s3))!=y.s2)||((max(x.s1,max(x.s2,x.s3))==x.s2&&max(y.s1,max(y.s2,y.s3))==y.s2)&&x.s2-max(x.s1,x.s3)<y.s2-max(y.s1,y.s3));
}
bool cmp3(s x,s y)
{
	return (max(x.s1,max(x.s2,x.s3))==x.s3&&max(y.s1,max(y.s2,y.s3))!=y.s3)||((max(x.s1,max(x.s2,x.s3))==x.s3&&max(y.s1,max(y.s2,y.s3))==y.s3)&&x.s3-max(x.s1,x.s2)<y.s3-max(y.s1,y.s2));
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>k[i].s1>>k[i].s2>>k[i].s3;
		ll ans=0,a=0,b=0,c=0;
		for(int i=1;i<=n;i++)
		{
			ans+=max(max(k[i].s1,k[i].s2),k[i].s3);
			if(k[i].s1>=k[i].s2&&k[i].s1>=k[i].s3)a++;
			else if(k[i].s2>=k[i].s1&&k[i].s2>=k[i].s3)b++;
			else if(k[i].s3>=k[i].s1&&k[i].s3>=k[i].s2)c++;
		}
		if(a>n/2)
		{
			sort(k+1,k+n+1,cmp1);
			for(int i=1;i<=a-n/2;i++)ans-=(k[i].s1-max(k[i].s2,k[i].s3));
		}
		if(b>n/2)
		{
			sort(k+1,k+n+1,cmp2);
			for(int i=1;i<=b-n/2;i++)ans-=(k[i].s2-max(k[i].s1,k[i].s3));
		}
		if(c>n/2)
		{
			sort(k+1,k+n+1,cmp3);
			for(int i=1;i<=c-n/2;i++)ans-=(k[i].s3-max(k[i].s1,k[i].s2));
		}
		cout<<ans<<'\n';
	}
	return 0;
}
