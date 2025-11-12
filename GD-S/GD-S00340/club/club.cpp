#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int t,n,sum,ans;
int a[100005][4],cnt[4];
void dp(int num)
{
	if(num==n+1)
	{
		ans=max(ans,sum);
//		cout<<"ans:"<<ans<<"\n\n";
		return;
	}
	if(cnt[1]<n/2)
	{
		sum+=a[num][1];
		cnt[1]++;
//		cout<<1<<" "<<sum<<"\n";
		dp(num+1);
		sum-=a[num][1];
		cnt[1]--;
	}
	if(cnt[2]<n/2)
	{
		sum+=a[num][2];
		cnt[2]++;
//		cout<<2<<" "<<sum<<"\n";
		dp(num+1);
		sum-=a[num][2];
		cnt[2]--;
	}

	if(cnt[3]<n/2)
	{
		sum+=a[num][3];
		cnt[3]++;
//		cout<<3<<" "<<sum<<"\n";
		dp(num+1);
		sum-=a[num][3];
		cnt[3]--;
	}
}
	
	
bool cmp(int a,int b)
{
	return a>b;
}	
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t)
	{
//		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		int temp=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)cin>>a[i][j];
			if(a[i][2]==0&&a[i][3]==0)temp++;
		}
		if(n<=10)
		{
			ans=0;
			dp(1);
			cout<<ans<<"\n";
		}
		else if(temp==n)
		{
			int a1[100005];
			for(int i=1;i<=n;i++)a1[i]=a[i][1];
			sort(a1+1,a1+n+1,cmp);
			ans=0;
			for(int i=1;i<=n/2;i++)ans+=a1[i];
			cout<<ans<<"\n";
		}
		t--;
	}
	
	//25pts
	return 0;
 } 
