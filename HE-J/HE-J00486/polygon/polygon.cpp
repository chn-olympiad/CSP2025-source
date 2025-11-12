#include<bits/stdc++.h>
using namespace std;

int n;
int a[5004];
int sum,maxn;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);	
	if(n==3)
	{
		sum=a[1]+a[2]+a[3];	
		maxn=max(a[1],max(a[2],a[3]));
		if(sum>2*maxn)
			cout<<1;
		else
			cout<<0;
		return 0;		
	}	
	
	return 0;
}

