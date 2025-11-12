#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	LL n,a,b,c,k,maxn=0;
	
	cin>>n;
	if(n<=3){
		cin>>a>>b>>c;
		if(a+b>c&&a+c>b&&b+c>a){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		for(LL i=1;i<=n;i++){
			cin>>k;
			maxn=max(maxn,k);
		}
		if(maxn==1){
			cout<<n/3;
		}
	}
	return 0;
}
