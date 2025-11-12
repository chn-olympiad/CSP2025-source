#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m;
string s;
int c[505];
long long A(int n,int m){
	long long ans=1;
	for(int i=1;i<=m;i++){
		ans*=n;
		n--;
		ans%=mod;
	}
	return ans;
}
int cnt,fl;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	cout<<A(n,n);
	return 0;
}

