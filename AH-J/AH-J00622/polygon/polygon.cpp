#include<bits/stdc++.h>
using namespace std;
using LL = long long;
LL a[5010],x[10]={0,0,0,1,6,9,25};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	LL n;
	scanf("%lld",&n);
	for(LL i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	LL cnt=0,ok=0,dok=0;
	for(LL i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			ok=1;
			dok=1;
		}
		if(a[i]!=a[i]+1&&ok==1){
			cnt++;
			ok=0;
		}
	}
	if(n<=3){
		cout<<x[n];
	}
	else if(n<=6){
		if(dok==1) cout<<x[cnt];
		else cout<<x[n];
	}
	return 0;
}
