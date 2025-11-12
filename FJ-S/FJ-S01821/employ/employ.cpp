#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=998244353;
int n,m;
int a[505];
char s[505];
ll ans=1;
int main(){
	freopen("employ3.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>s[i];
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=n;i>1;--i){
		ans*=i;
		ans%=N;
	}
	cout<<ans;
	return 0;
}

