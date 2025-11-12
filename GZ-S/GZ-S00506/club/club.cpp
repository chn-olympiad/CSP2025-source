//GZ-S00506 黄春阳 华东师范大学附属贵阳学校 
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,z;
};
node a[100005];
int A[100005];
long long ans=0;
int n;
void dfs(int step,long long tans,int cnt1,int cnt2,int cnt3)
{
 	if(step>n)
	{
	 	ans=max(tans,ans);
	 	return ;
	} 
	if(cnt1<n/2&&cnt2<n/2&&cnt3<n/2)
	{
		dfs(step+1,tans+a[step].x,cnt1+1,cnt2,cnt3);
		dfs(step+1,tans+a[step].y,cnt1,cnt2+1,cnt3);
		dfs(step+1,tans+a[step].z,cnt1,cnt2,cnt3+1);
	}
	else
	{
		if(cnt1<n/2)
			dfs(step+1,tans+a[step].x,cnt1+1,cnt2,cnt3);
		if(cnt2<n/2)
			dfs(step+1,tans+a[step].y,cnt1,cnt2+1,cnt3);
		if(cnt3<n/2)
			dfs(step+1,tans+a[step].z,cnt1,cnt2,cnt3+1);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			A[i]=a[i].x;
		}
		if(n<=30)//小于30点 
		{
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
		}
		else
		{
			sort(A+1,A+n+1);
			for(int i=n;i>n/2;i--)
				ans+=A[i];
			cout<<ans<<endl;
		}
		ans=0;
	}
	return 0;
} 

