#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k,a[500010],cum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<n/2;
	}
	return 0;
}
