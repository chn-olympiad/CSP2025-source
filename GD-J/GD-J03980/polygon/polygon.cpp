#include<bits/stdc++.h>
using namespace std;
int n,d[5005];
bool wt(){
	if(d[1]+d[2]>d[3]) return 1;
	return 0;
}
int wallone(int n){
	return n-2;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>d[i];
	}
	sort(d+1,d+n+1);
	if(n==3){
		if(wt()) cout<<1%998244353;
		else cout<<0%998244353;
		return 0;
	}
	if(d[n]==1){
		cout<<wallone(n)%998244353;
		return 0;
	}
	return 0;
}
