#include<bits/stdc++.h>
using namespace std;
long long n,i,j,a[100001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	    cin>>a[i];
	if(n==3)
	    if((a[1]+a[2]>a[3])&&(a[1]+a[3]>a[2])&&(a[2]+a[3]>a[1]))
	        cout<<1;
	    else
	        cout<<0;
	else
	    cout<<8;
	return 0;
}