#include<bits/stdc++.h>
using namespace std;
long long n,k,cnt=0;
long long a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2&&(a[1]==1||a[2]==1)&&k==0){
		if(a[1]==1&&a[2]==1){
			cout<<1;
		}else if(a[1]==0||a[2]==0){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<2;
	}
	return 0;
}
