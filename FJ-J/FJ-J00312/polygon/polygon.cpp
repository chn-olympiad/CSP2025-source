#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int n,a[N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int ans,k=0,x=-1;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		k+=a[i];	
	}
	for(int i=1;i<=n;i++) {
		if(a[i]>x) x=a[i];
	}
	if(k>2*x) ans=1;
	else ans=0;
	cout<<ans%998244353;
	return 0;
}