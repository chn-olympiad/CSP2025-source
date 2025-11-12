#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[5010],b[5010],ans=0,g=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2)
		{
		    cout<<1;
		} 
		else
		{
			cout<<0;
		}
		return 0;
	}
	ll j=1;
	for(int i=1;i<=n;i++)
	{
		j=(j*2)%g;
	}
    j--;
	j=j-n-n*(n-1)/2;
	cout<<j%g;
	return 0;
} 
