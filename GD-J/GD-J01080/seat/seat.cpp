#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[10000011],b[10000001],n,m,j,k,l,c,d,x,y,ans,sum;
int cmp(int a,int b){
	return a>b;
}
main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	c=a[1];
	d=n*m;
	sort(a+1,a+d+1,cmp);
	for(int i=1;i<=d;i++)
	{
		if(c==a[i]){
			ans=i;
			break;
		}
	}
	sum=1;
	for(int i=1;;i++)
	{
		if(ans-n>0)ans-=n,sum++;
		else break;
	}
	if(sum%2==1){
		cout<<sum<<" "<<ans,exit(0);
	}
	cout<<sum<<" "<<n-ans+1;
}
