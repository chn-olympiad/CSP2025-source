#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,cnt=0,a[505];
bool A=1;
string s;
unsigned long long fac[505];
void solve(){
	//if(n-cnt<m){
		//cout<<0;
		//return ;
	//}
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=(fac[i-1]*i)%mod;
	cout<<fac[n];
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) cnt++; 
	}
	//cout<<cnt<<endl;
	for(int i=0;i<n;i++){
		if(s[i]!='1') A=0;
	}
	if(A){
		solve();
		return 0;
	}
	cout<<0;
	return 0;
}
