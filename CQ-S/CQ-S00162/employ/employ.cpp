#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int mod=998244353;
const int N=505;
int n,m;
string s;
int c[N],f[N];
void jiechen(int x){
	f[0]=1;
	for(int i=1;i<=x;i++){
		f[i]=f[i-1]*i%mod;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	bool v=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			v=1;
			break;
		}
	}
	if(v&&m==n){
		cout<<"0";
		return 0;
	}
	jiechen(n);
	cout<<f[n];
	return 0;
} 
