#include<bits/stdc++.h>
#define N 510
using namespace std;
int n,m,c[510],go[510];
string s;

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	cin>>s;
	int sum=0,ans=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(sum>=c[i]||s[i-1]=='0') sum++;
		go[i]=i;
	}
	if(sum<=n-m){
		ans++;
	}
	while(next_permutation(go+1,go+n+1)){
		for(int i=1;i<=n;i++){
			if(sum>=c[go[i]]||s[i-1]=='0') sum++;
		}
		if(sum<=n-m) ans++;
		sum=0;
	}
	cout<<ans<<'\n';
	return 0;
}
