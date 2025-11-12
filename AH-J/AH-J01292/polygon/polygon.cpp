#include <bits/stdc++.h>
using namespace std;
int n,ans=0,a[5000];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=2){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	if(a[1]+a[2]+a[3]>2*a[3]) cout<<1;
	else cout<<0;
		return 0;
}
