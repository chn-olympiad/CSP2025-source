#include<bits/stdc++.h>
const long long Mod=998244353;
using namespace std;
long long A(int s,int x){
	int a1=1;
	for(int i=1;i<=s;i++){
		a1*=x;
		a1%=Mod;
		x--;
	}
	return a1;
}
long long C(int s1,int x1){
	return A(s1,x1)/A(s1,s1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	long long ans=0;
	for(int i=3;i<=n;i++){
		ans+=C(i,n);
		ans%=Mod;
	}
	cout<<ans<<endl;
	return 0;
}

