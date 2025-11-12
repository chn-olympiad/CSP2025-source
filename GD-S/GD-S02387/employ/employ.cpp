#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=502,M=998244353;
//争取性质A的点 
ll n,m,c[N];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int cnt=0;
	for(int i=1;i<=m;i++){
		cin>>c[i];
		if(c[i]==0) cnt++;
	}
	if(cnt==n){
		cout<<0;
		return 0;
	}
	ll nm=1,mn=1;
	for(int i=1;i<=n-cnt;i++) nm=nm*i%M;
	for(int i=1;i<=cnt;i++) mn=mn*i%M;
	ll ans=nm*mn%M;
	cout<<ans;
	return 0;
}
