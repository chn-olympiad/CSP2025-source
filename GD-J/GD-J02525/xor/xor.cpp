#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],q[500005][25],ans=0;
int qj(int x,int y)
{
	int s=0;
	for(int i=0;i<20;i++)
		if((q[y][i]-q[x-1][i])%2) s+=pow(2,i);
	return s;
}
bool chack(long long d)
{
	int I=1,s=0;
	while(s<d)
	{
		int o=1;
		for(int ii=I;ii<=n;ii++)
		{
			for(int jj=ii;jj<=n;jj++)
			{
				if(qj(ii,jj)==k)
				{
					I=jj+1;
					s++;
					o=0;
					break;
				}
			}
			if(!o) break;
		}
		if(o) return 0;
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int s=a[i],xb=0;
		while(s)
		{
			q[i][xb]=q[i-1][xb]+s%2;
			s/=2;
			xb++;
		}
		for(int j=0;j<20;j++) if(!q[i][j]) q[i][j]=q[i-1][j];
	}
	int l=0,r=n,ans=0;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if(chack(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
