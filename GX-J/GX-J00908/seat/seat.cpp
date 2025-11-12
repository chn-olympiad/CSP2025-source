#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;
#define ll long long
ll n,m,a[101],k,t;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>=a[1]) k++;
	}
	t=k/n;
	if(k%n!=0) t++;
	k=k-n*(t-1);
	if(t%2==0)
		k=n-k+1;
	cout<<t<<" "<<k;
	return 0;
}
	
