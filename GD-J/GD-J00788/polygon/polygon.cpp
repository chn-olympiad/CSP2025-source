#include<bits/stdc++.h>
using namespace std;
bool f(vector<int> l){
	long long sum,maxL;
	if(l.size()<3)return 0;
	for(int L:l){
		sum+=L;
		maxL=max(maxL,(long long)L);
	}
	return sum-2*maxL>0;
}
long long g(int n){
	long long ans=1;
	for(int i=1;i<=n;i++)ans*=i,ans%=998244353;
	return ans;
}
long long C(int n,int m){
	if(n>m/2)return C(m-n,m);
	return g(m)/g(n)/g(m-n);
}
int n,ans;
vector<int> a(5010),b(5010);
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<3)cout<<f(a);
	else{
		for(int i=3;i<=n;i++)ans+=C(i,n);
		cout<<ans;
	}
	return 0;
}
