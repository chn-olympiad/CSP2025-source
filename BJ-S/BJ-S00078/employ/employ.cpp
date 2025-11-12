#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
string s;
int c[505];
long long jiecheng(long long n){
	if(n==0||n==1) return 1;
	return (n*jiecheng(n-1))%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>s;
	int t=n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) t--;
	}
	cout<<jiecheng(t)<<endl;
	return 0;
}
