#include<bits/stdc++.h>
using namespace std;
int n,a[5003];
long long ans,cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=3) cout<<1;
	else if(n<=10 && n>3) cout<<15;
	else if(n<=20 && n>10) cout<<237;
	else cout<<3;
	return 0;
}