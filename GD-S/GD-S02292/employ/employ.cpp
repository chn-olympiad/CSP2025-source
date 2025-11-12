#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,cnt,tmp,a[505];
char c;
bool b[505];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>c,b[i]=c-'0',cnt+=b[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	if(cnt==n){
		tmp=1;
		for(int i=2;i<=n;i++) tmp=tmp*i%mod;
		cout<<tmp;
		return 0;
	}
	return 0;
}
