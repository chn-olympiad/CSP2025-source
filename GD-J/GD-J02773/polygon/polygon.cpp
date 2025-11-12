#include<bits/stdc++.h>
using namespace std;
const long long M=998244353;

long long n,a[5145],ans;
//long long cc[5145],t;

void dfs(long long yxmax,long long lh,long long wz,long long sl)
{
	if(wz>n)
	{
		if(sl>n) return;
		if(lh>yxmax*2&&sl>=3)
		{
			ans++;
			ans%=M;
			//for(int i=1;i<=t;i++) cout<<cc[i]<<" ";
			//cout<<endl;
		}
		return;
	}
	
	long long nyxmax=-1,nwz=wz+1; 
	if(a[nwz]>yxmax) nyxmax=a[nwz];
	else nyxmax=yxmax; 
	if(a[nwz]!=0)
	{
		//cc[++t]=a[nwz];
		dfs(nyxmax,lh+a[nwz],nwz,sl+1);
		//t--;
	}
	
	dfs(yxmax,lh,nwz,sl);
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,0,0,0);
	cout<<ans%M;
	return 0;
}
