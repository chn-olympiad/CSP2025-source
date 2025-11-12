#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	bool p=0,p1=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)p=1;
		if(a[i]==0)p1=1;
	}
	if(k==0&&p==0&&p1!=1) 
	{
		if(n%2==0)cout<<n/2;
		else if(n%2==1&&n!=1) cout<<n/2;
		else if(n==1)cout<<0;
	}
	else if(k==0&&p1==1)cout<<0;
	return 0;
}
