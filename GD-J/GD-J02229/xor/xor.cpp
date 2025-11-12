#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,anss;
long long s[500050];
long long xb[500050];
long long tmax[500050];
void dp()
{
	bool canadd=0;
	for(int i=1;i<=n;i++)
	{
		ans=0;
		xb[i]=0;
		canadd=0;
		for(int j=i;j<=n;j++)
		{
			if(ans==0)ans=s[j];
			else ans=ans^s[j];
			if(ans==k){xb[i]=j;canadd=1;
			break;}
		}
		tmax[i]=canadd;
		for(int j=1;j<=i-1;j++)
		{
			if(i>xb[j])tmax[i]=max(tmax[i],tmax[j]+canadd);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(tmax[i]>anss)anss=tmax[i];
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>s[i];
	dp();
	cout<<anss;
	return 0;
}
