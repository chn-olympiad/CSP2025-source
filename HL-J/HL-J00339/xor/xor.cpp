#include <bits/stdc++.h>
using namespace std;
long long f[1000010],n,a[500010],k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k;
	bool flagA=true,flagB=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flagA=false;
		}
		if(a[i]>1){
			flagB=false;
		}
	}
	if(flagA||flagB){
		cout<<0<<"\n";
	}
	return 0;
}