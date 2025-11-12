#include<bits/stdc++.h>
using namespace std;
int a[1000];    
int x,y;
int h;
int wpd(int a,int h)
{   x=1;y=1;
    for(int i=0;i<=a-1;i++)x=x*(h-i);
    for(int i=a;i>=1;i--)y=y*i;	
    return x/y;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	int j=1;
	while(2*j<=n)
	{
		ans=ans+wpd(2*j,n);
		j++;
	}
	cout<<ans;
    return 0;
}
