#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T;
int n;
int V1[100005],V2[100005],V3[100005];


long long cnt1,cnt2,cnt3;
long long maxn;
long long M1[100005],M2[100005],M3[100005];
long long check(){
	long long sum=0;
	for(int i=1;i<=n/2;i++)
	{
		sum+=M1[i];
		sum+=M2[i];
		sum+=M3[i]; 
	}
	return sum;
}

long long check2(){
	long long sum=0;
	for(int i=1;i<=n/2;i++)
	{
		sum+=M1[i];
		sum+=M2[i];
	}
	return sum;
}
void dfs(int dp){
	if(dp==n+1)
	{
		if(check()>maxn)
		{
			maxn=check();
		}
		return ;
	}
	if(cnt1<n/2)
	{
		M1[++cnt1]=V1[dp];
		dfs(dp+1);
		M1[cnt1]=0;
		cnt1--;
	}
	if(cnt2<n/2)
	{
		M2[++cnt2]=V2[dp];
		dfs(dp+1);
		M2[cnt2]=0;
		cnt2--;
	}
	if(cnt3<n/2)
	{
		M3[++cnt3]=V3[dp];
		dfs(dp+1);
		M3[cnt3]=0;
		cnt3--;
	}
	dfs(dp+1);
	return ;
}


void dfs2(int dp){
	if(dp==n+1)
	{
		if(check2()>maxn)
		{
			maxn=check2();
		}
		return ;
	}
	if(cnt1<n/2)
	{
		M1[++cnt1]=V1[dp];
		dfs(dp+1);
		M1[cnt1]=0;
		cnt1--;
	}
	if(cnt2<n/2)
	{
		M2[++cnt2]=V2[dp];
		dfs(dp+1);
		M2[cnt2]=0;
		cnt2--;
	}
	dfs(dp+1);
	return ;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//freopen("club.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cnt1=0;
		cnt2=0;
		cnt3=0;
		memset(M1,0,sizeof M1);
		memset(M2,0,sizeof M2);
		memset(M3,0,sizeof M3);
		maxn=-1;
		cin>>n;
		int flag3=0,flag2=0;
		for(int j=1;j<=n;j++)
		{
			cin>>V1[j]>>V2[j]>>V3[j];
			if(V3[j]!=0)
			{
				flag3=1;
			}
			if(V2[j]!=0)
				flag2=1;
		}
		if(flag3==1&&flag2==1)
		{
			dfs(1);
		}
		else if(flag3==0&&flag2==1)
		{
			dfs2(1);
		}
		else if(flag3==0&&flag2==0)
		{
			sort(V1+1,V1+n+1);
			maxn=0;
			for(int i=n;i>n/2;i--)
			{
				maxn+=V1[i];
			}
		}
		cout<<maxn<<endl;
	}
	return 0;
}
