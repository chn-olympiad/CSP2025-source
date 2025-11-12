#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,c[510],tot,ans=1;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;tot=n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)tot--;
	}
	for(int i=1;i<=tot;i++){
		ans=(ans*i)%998244353;
	}
	printf("%d",ans);
	return 0;
}
