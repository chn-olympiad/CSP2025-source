#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>=a[1])t++;
	}
	long long x=t/n,y=t%n;
	if(y==0)
	{
		if(x%2==1)cout<<x<<" "<<n;
		else cout<<x<<" "<<1;
	}
	else
	{
		if(x%2==1)cout<<x+1<<" "<<n-y+1;
		else cout<<x+1<<" "<<y;
	}
	return 0;
}
