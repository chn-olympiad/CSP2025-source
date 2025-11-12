#include<bits/stdc++.h>
using namespace std;
int n,a[10005],ans,maxx;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) ans+=a[i],maxx=max(maxx,a[i]);
	if(ans>maxx*2) cout<<1;
	else cout<<0;
	
	return 0;
 } 
