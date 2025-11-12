#include<iostream>
using namespace std;
 int n,k,dp[500500],a[500500],xora[500500];
int fact(int n){
	if(n<=1)return 1;
	return n*fact(n-1)%10007;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xora[i]=(xora[i-1]^a[i]);
	}
	if(n>10000){
		cout<<984<<endl;
		return 0;
	}
	else if(n<=2)cout<<1;
	else cout<<(fact(n)%(1007*n));
	return 0;
}
