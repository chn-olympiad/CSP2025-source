#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],flag=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=1;
	}
	if(flag==0&&k==0){
		cout<<n/2;
		return 0;
	}
}
