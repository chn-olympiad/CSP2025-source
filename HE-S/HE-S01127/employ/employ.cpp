#include<bits/stdc++.h>
using namespace std;
const int MODNUM=998244353;
int a[505];
int jc(int n){
	int ans;
	for(int i=2;i<=n;i++){
		ans*=i;
	}
	return ans;
}
int f(int n,int m){
	return jc(n)/(jc(m)*jc(n-m));
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<f(n,m);
	return 0;
}
