#include<bits/stdc++.h>
using namespace std;
int n,victory000;
long long k,a[50050];
int dp[60050];
long long pd[60060],vx[50050];
bool XoR(int a1,int a2)
{
	int fTw=a2-a1;
	long long m=0,lkl;
	if(a1==a2 && a[a1]==k)
	    return true;
	for(int i=0;i<=fTw;i++)
	{
		vx[i+1]=a[a1+i];
		m+=vx[i+1];
	}
	m=m-k;
	if(m<0)
	    return false;
	if(m%2==1)
	{
		return false;
	}
	m/=2;
	fTw++;
	sort(vx+1,vx+fTw+1);
	for(int i=fTw;i>=1;i--)
	{
		lkl=0;
		if(vx[i]>m)
		{
			continue;
		}
		for(int j=fTw;pd[j]+vx[i]<=m;j++)
		{
			lkl=pd[j]+vx[i];
		}
		pd[i]=max(pd[i+1],lkl);
	}
	if(pd[1]==m)
	{
		return true;
	}
	return false;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		victory000=0;
		dp[i]=dp[i-1];
		for(int j=i;j>=1 && dp[j-1]==dp[i-1];j--)
		{
			if(XoR(j,i))
			{
				victory000++;
				break;
			}
		}
		dp[i]+=victory000;
	}
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}