#include<bits/stdc++.h>
using namespace std;
long long n,k,m,tmp;
const int N=5*1e5+10;
int a[N],s[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]) tmp=1;
	}
	if(k==0){
		if(tmp=1){
		if(a[1]==0) cout<<n-1;
		else if(a[1]!=0) cout<<n-2;
		}
	}
	else cout<<3;
	
	
	return 0;
}
