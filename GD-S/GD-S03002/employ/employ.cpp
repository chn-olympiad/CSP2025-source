#include<bits/stdc++.h>
using namespace std;
const int N=1;
const int mod=998244353;
int jc(int x){
	//cout<<1;
	if(x<=1)return 1;
	return 1ll*jc(x-1)%mod*1ll*x%mod;
}int n;
int slove(){
	cin>>n;
	cout<<jc(n);
	return 0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int t=1;//cin>>t;
	while(t--)
		slove();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
