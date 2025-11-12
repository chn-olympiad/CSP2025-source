#include<bits/stdc++.h>
using namespace std;
int a[5010];
int n,ans;
int main()
{
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)
	{
	cin>>a[i];
	}
sort(a+1,a+n+1);	
if(a[1]+a[2]+a[3]>a[n]*2)
	ans++;
cout<<ans;
return 0;						
}
