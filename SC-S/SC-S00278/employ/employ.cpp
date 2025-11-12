#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N],ans=1;
char a[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[N];
	}
	for(int i=1;i<=n;i++){
		ans=(ans*i)%mod;
	}
	cout<<ans<<'\n';
	return 0;
}