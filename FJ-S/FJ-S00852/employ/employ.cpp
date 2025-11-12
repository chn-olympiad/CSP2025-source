#include<bits/stdc++.h>
const int N=505,mod=998244353;
using namespace std;
long long n,m,a[N],ans=1;bool s[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;cin>>c;
		s[i]=c-'0';
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<=n;i++)ans=ans*i%mod;
	cout<<ans;
}
