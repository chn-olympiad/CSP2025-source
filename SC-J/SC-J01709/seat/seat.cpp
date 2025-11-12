#include<bits/stdc++.h>
#define int long long
using namespace std;
int c[10001];
int n,m,a;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>c[i];
		if(c[i]>c[1])
			a++;
	}
	if(a%n==0||(a+1)%n==0)
	{
		if(a%n==0)
		{
			if((a/n+1)%2==1)
				cout<<a/n+1<<" "<<1;
			else
				cout<<a/n+1<<" "<<n;
		}
		else
		{
			if((a/n)%2==1)
				cout<<a/n+1<<" "<<1;
			else
				cout<<a/n+1<<" "<<n;
		}
		
	}
	else
	{
		if(a/n%2==0)
			cout<<a/n+1<<" "<<a%n+1;
		else
			cout<<a/n+1<<" "<<n-a%n+1;
	}
	return 0;
}