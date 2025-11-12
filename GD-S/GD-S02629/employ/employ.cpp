#include<bits/stdc++.h>
#define N 505
#define int long long
using namespace std;
int n,m,pre[N],c[N];
const int mod=998244353;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		char a=getchar();
		while(a!='0'&&a!='1') a=getchar();
		pre[i]=pre[i-1];
		if(a=='0') ++pre[i];
	}
	for(int i=1;i<=n;++i){
		cin>>c[i];
		if(!c[i]) --n,--i;
	}
	if(!pre[n]){
		int ans=1;
		for(int i=2;i<=n;++i)
			ans=ans*i%mod;
		cout<<ans;
	}
	else
		cout<<0;
	return 0;
}
