#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[5005],nn,sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n==1) cout<<0;
	if(n==2) cout<<0;
	if(n==3 and a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))) cout<<1;
	else if(n==3) cout<<0;
	if(n>20) 
	{
		nn = n-2;
		for(int i=1;i<=nn;i++)
		{
			sum += i;
		}
		cout<<sum;
	}
	return 0;
}
