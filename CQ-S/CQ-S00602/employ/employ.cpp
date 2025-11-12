#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int n,m,c[505];
int mod=998244353;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	int a=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0){
			a++;
		}
	}
	int sum=1;
	for(int i=1;i<=m;i++){
		sum*=(a-i+1);
		sum%=mod;
	}
	cout<<sum%mod;
}
