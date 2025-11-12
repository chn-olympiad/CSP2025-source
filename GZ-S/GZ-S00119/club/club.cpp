//GZ-S00119 贵阳市清华中学 喻宥诚 
#include<bits/stdc++.h>
using namespace std;
int t,n,sum,b,mmax=INT_MIN;
int a[100005][4];


void dp(int num,int ch,int su,int p1,int p2,int p3)
{
	
	if(p1>n/2||p2>n/2||p3>n/2)
	{
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(i==1)
		{
			dp(num+1,i,su+a[num][i],p1+1,p2,p3);
		}else if(i==2)
		{
			dp(num+1,i,su+a[num][i],p1,p2+1,p3);
		}else if(i==3)
		{
			dp(num+1,i,su+a[num][i],p1,p2,p3+1);
		}
	}
	if(num>=n)
	{
		mmax=max(mmax,su);
		return;
	}
	return;
}

void solve()
{
	cin>>n;
	sum=0;
	if(n>=10000){
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			sum+=max(max(a[i][1],a[i][2]),a[i][3]);	
		}
		cout<<sum<<'\n';
	}else {
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];	
		}
		dp(1,1,0,0,0,0);
		cout<<mmax<<'\n';
		mmax=INT_MIN;
		memset(a,0,sizeof(a));
	}
	return;
}


int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		solve();
	}
	return 0;
}
