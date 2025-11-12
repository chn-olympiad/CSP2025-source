#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],s,m=998244353;
long long kn(int i,int j,int s)
{
	if(s==2&&a[j]+a[j+1]>a[i])return (i-j-1)*(i-j-1)%m;
	return kn(i,j+1,s-1)*kn(i,j,s-1)%m;
}
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
		for(int j=1;j<n-1;j++)
			for(int k=2;k<=i-j;k++)
			{
				s+=kn(i,j,k);
				
			}
	cout<<s%m;
	return 0;
}
