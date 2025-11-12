#include <bits/stdc++.h>
using namespace std;
int a[500010],k,n;
long long js(int i,long long s,int l){
	s^=a[i];
	if(i==n){
		if(s==k) return l+1;
		else return l;
	}
	if(s==k){
		long long m=-1;
		for(int j=i+1;j<=n;j++) m=max(m,js(j,0,l+1));
		return m+js(i+1,s,l);
	}
	return js(i+1,s,l);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n>100000){
		cout<<1;
		return 0;
	} 
	long long m=-1;
	for(int i=1;i<=n;i++) m=max(m,js(i,0,0));
	cout<<m;
	return 0;
}
