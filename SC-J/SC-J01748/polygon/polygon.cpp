#include<bits/stdc++.h>
using namespace std;
long long n,maxn=0;
long long a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=false;
	}
	if(flag){
		cout<<n-2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		maxn=max(maxn,a[i]);
	}
	if(a[1]+a[2]+a[3]>2*maxn) cout<<1;
	return 0;
}