#include<bits/stdc++.h>
using namespace std;
long long e[5005][5005],ans;
int n,a[5005];
long long mu(int x,int y,int z)
{
	if(x>n&&y>z*2)return 1;
	long long o=0;
	for(int i=x;i<=n;i++)
		o+=(mu(i+1,y+a[i],max(z,a[i]))+mu(i+1,y,z))%998244353;
	return o%998244353;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	cout<<mu(1,0,0);
	return 0;
}