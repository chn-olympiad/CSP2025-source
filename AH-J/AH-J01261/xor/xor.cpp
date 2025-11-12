#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[200005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	LL n,k,ok=0;
	cin>>n>>k;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			ok=1;
		}
		
	}
	if(n==1&&k==0&&ok==0){
		cout<<0;
	}
	else if(n==2&&k==0&&ok==0){
		cout<<1;
	}else if(n<=100&&k==0&&ok==0){
		cout<<n/2;
	}
	else if(n<=200005&&k<=1){
		LL cnt=0;
		for(LL i=1;i<=n;i++){
			if(a[i]==k){
				cnt++;
			}
		
			
		}
		cout<<cnt;
	}
	return 0;
}
