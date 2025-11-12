#include<bits/stdc++.h>
using namespace std;
int n,a[5001],sum,maxn,cnt=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sum=a[1]+a[2]+a[3];
	maxn=max(a[1],max(a[2],a[3]));
	if(maxn*2<sum) cout<<1;
	else cout<<0;
	return 0;
}
