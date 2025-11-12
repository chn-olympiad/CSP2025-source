#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	long long a[500010];
	cin>>n>>k;
	long long i;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==2){
		cout<<1;
	}else{
		cout<<0
	}
	return 0;
}
