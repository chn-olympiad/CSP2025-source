#include<bits/stdc++.h>
using namespace std;
long long n,a[50005],aa[50005],z;
void cctv(int zd,int zh,int wz,int gs)
{
	for(int i=wz+1;i<=n;i++)
	{
		if(gs+1>=3&&zh+a[i]>zd)z++;
		 
		cctv(zd,zh+a[i],i,gs+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>aa[i];
	}
	sort(aa+1,aa+n+1);
	for(int i=n,j=1;i>=1;i--,j++)
	{
		a[j]=aa[i];
	}
	for(int j=1;j<=5;j++)
	{
		cctv(a[j]*2,a[j],j,1);
	}
	cout<<z;
	return 0;
} 
