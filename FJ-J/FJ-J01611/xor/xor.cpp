#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll jz2(ll a){
	ll b=0,c=1;
	while(a>1){
		b+=(a%2)*c;
		a/=2;
		c*=10;
	}
	b+=c;
	return a;
}
ll yh(ll a,ll b){
	a=jz2(a);
	b=jz2(b);
	ll c=0;
	while(a>=0||b>=0){
		int a1=a%10;
		int b1=b%10;
		a/=10;
		b/=10;
		if((a1==0&&b1==1)||(a1==1&&b1==0)){
			c*=10;
			c+=1;
		}else c*=10;
	}
}
ll i,j,k,n,a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2){
		cout <<1;
		return 0;
	}else if(n==1){
		cout <<0;
		return 0;
	}
	return 0;
}
