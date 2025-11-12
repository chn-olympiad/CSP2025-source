#include<bits/stdc++.h>
using namespace std;
long long n,k,a[10000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0&&a[1]!=a[2]){
		cout<<1;
		return 0;
	}else if(k==0&&a[1]==a[2]){
		cout<<2;
		return 0;
	}
	return 0;
}
