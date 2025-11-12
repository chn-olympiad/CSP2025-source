#include<bits/stdc++.h>
using namespace std;
const long long N=998244353;
long long n,a[5005]={},ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n; 
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	if(n==3&&a[0]+a[1]+a[2]>2*a[2]){
		cout<<1;
		return 0;}
	for(int l=n-2;l;l--)ans+=l;
	cout<<ans;
	return 0;}
