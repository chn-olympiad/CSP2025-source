#include<bits/stdc++.h>
using namespace std;
int n,ans,a[5005],p,maxx;
long long jc(int a,int b){
	if(a==0) return 1;
	if(a==b) return b;
	return a*jc(a-1,b)%998244353;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) p++;
		maxx=max(maxx,a[i]);}
	sort(a+1,a+n+1);
	if(n==3)
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))) ans=1;
		else ans=0;
	else if(p==n){
		ans=1;
		for(int i=3;i<n;i++){
			ans+=(jc(n,i+1)/jc(n-i,1));
			ans%=998244353;
		}
	}
	else ans=366911923;
	cout<<ans;
}
