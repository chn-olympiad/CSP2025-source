#include<bits/stdc++.h>
using namespace std;
int r,ch;
int mod=998244353;
int y[5010];
int jizhi(int q,int s)
{
	int f=1;
	while(s--) f*=q;
	return f;
}
int baoli(int z,int b,int zi,int ma)
{
	int ans=0;
	if(z+b<3) return 0;
	if(zi>=ma*2 && b>=3) ans=1;
	if(z==1) return 0;
	return ans+baoli(z-1,b+1,zi+y[z],max(ma,0))+baoli(z-1,b,zi,ma);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>r;
	for(int u=1;u<=r;u++)
	{
		cin>>y[u];
	}
	sort(y+1,y+r+1);
	cout<<baoli(r,0,0,0)%mod;
	return 0;
 } 
