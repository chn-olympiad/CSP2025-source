#include<bits/stdc++.h>
using namespace std;
const int inf=100;
int n,m;
int p[inf];
bool s[inf];
int c[inf];
inline bool sol(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		int o=p[i];
		if((!s[i])||(cnt>=c[o])) cnt++;
		// cout<<(!s[i])<<' '<<(cnt>=c[o])<<'\n';
		// cout<<o<<' '<<cnt<<'\n';
	}
	// cout<<cnt<<'\n';
	return (n-cnt>=m);
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	char oo;
	for(int i=1;i<=n;i++){
		cin>>oo;
		s[i]=oo-'0';
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	// for(int i=1;i<=n;i++) cout<<c[i];
	// cout<<'\n';
	for(int i=1;i<=n;i++) p[i]=i;
	int fac=1;
	for(int i=1;i<=n;i++) fac*=i;
	int ans=0;
	for(int i=1;i<=fac;i++){
		// for(int j=1;j<=n;j++) cout<<p[j]<<' ';
		// cout<<'\n';
		ans+=sol();
		next_permutation(p+1,p+1+n);
	}
	cout<<ans<<'\n';
}