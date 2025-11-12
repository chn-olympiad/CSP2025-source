#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,big;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	big=max(a[1],a[2],a[3]);
	if (n==3&&a[1]+a[2]+a[3]==big*2){
			cout<<1;
		}else{
			cout<<0;
		}
	return 0;
}
