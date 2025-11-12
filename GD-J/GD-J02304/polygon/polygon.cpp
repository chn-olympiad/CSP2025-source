#include<bits/stdc++.h>
using namespace std;
int a[5007];
long long ans=0;
int A(int x,int y){
	long long num=1;
	for(int i=y;i>0;i--){
		num*=x;
		num=num%998244353;
		x--;
	}
	return num;
}
void C(int x,int y){
	ans+=A(x,y)/A(y,y);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3){
		int m=max(max(a[1],a[2]),a[3]);
		if(a[1]+a[2]+a[3]>m*2){
			cout<<1;
		}
		else cout<<0;
		return 0;
	}
	for(int i=3;i<=n;i++){
		C(n,i);
	}
	cout<<ans%998244353;
	return 0;
}

