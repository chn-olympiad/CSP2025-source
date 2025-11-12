#include<bits/stdc++.h>
using namespace std;
long long n,m,k[501];
bool q[501],qq;
char c;
long long Max(long long x,long long y){
	if(x>y) return x;
	return y;
}
long long P(long long x){
	if(x<=1) return 1;
	return (P(x-1)*x)%998244353;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c;
		if(c=='1') q[i]=1;
		if(!q[i]) qq=1;
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
	}
	if(!qq){
		cout<<P(n);
		return 0;
	}
	return 0;
}
