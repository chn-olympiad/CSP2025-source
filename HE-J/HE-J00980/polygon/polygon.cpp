#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int ans=0;
int maxx=-1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		ans+=a[i];
	}
	if(ans>(2*maxx)) cout<<1;
	else cout<<0;
	return 0;
}
