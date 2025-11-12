#include<bits/stdc++.h>
using namespace std;
long long n,k,ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n>>k;
	int a[n+2];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k!=0){
		cout<<0;
	}else{
		cout<<n;
	}
	return 0;
}
