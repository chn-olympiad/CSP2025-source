#include<bits/stdc++.h>
using namespace std;
struct node{
	int num;
	int m;
}dp[700005];
int yh(int xx,int yy)
{
	int f[30],l;
	for(int i=1;;i++)
	{
		f[i]=0;
		int x=0,y=0;
		x=xx%2;
		y=yy%2;
		xx/=2;
		yy/=2;
		if(x==y) f[i]=0;
		else f[i]=1;
		if(xx==0&&yy==0)
		{
			l=i;
			break;
		}
	}
	int cf=1,ans=0;
	for(int i=1;i<=l;i++)
	{
		if(f[i]) ans+=cf;
		cf=cf*2;
	}
	return ans;
}
int n,k,a[700005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(a[1]==k)
	{
		dp[1].m=1;
		dp[1].num=1;
	}
	for(int i=2;i<=n;i++)
	{
		int r=dp[i-1].m;
		if(r<i)
		{
			int ben=a[i],nm=0;
			for(int j=i;j>r;j--)
			{
				if(ben==k)
				{
					nm=j;
					break;
				}
				ben=yh(ben,a[j-1]);
			}
			if(nm)
			{
				dp[i].num=dp[i-1].num+1;
				dp[i].m=i;
			}
			else
			{
				dp[i].num=dp[i-1].num;
				dp[i].m=dp[i-1].m;
			}
			
		}
	}
	
	cout<<dp[n].num;
	

	
	return 0;
}
