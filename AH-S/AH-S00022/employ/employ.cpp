#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define mod 998244353
using namespace std;
int A(int n,int m){
	int sum=1;
	for(int i=0;i<m;i++){
		sum*=(n-i);
	}
	return sum;
}
int C(int n,int m){
	return (A(n,m)/A(m,m));
}
int c[1145];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,p;
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;++i){
		cin>>c[i];
		if(c[i]!=0) p++;
	}
	ll ans=0;
	for(int i=m;i<=n;i++){
		ans+=C(p,i);
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}
//Ren5Jie4Di4Ling5%
