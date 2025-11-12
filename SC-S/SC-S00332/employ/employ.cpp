#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
const int mod=998244353;
int n,m,c[maxn];
string s;
long long ans=1;
int main(){
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		ans=(ans*(i%mod))%mod;
	}
	cout<<ans;
	return 0;
} 