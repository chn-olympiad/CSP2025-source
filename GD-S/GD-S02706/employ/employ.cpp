#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,N=520;
int n,m,a[N];
bool c[N];
long long ans;
char s[N];
void work(int k,int h){
	if(k>n&&h>=m){
		ans=(ans+1)%mod;
		return;
	}for(int i=1;i<=n;i++)if(!c[i]){
		c[i]=1;
		work(k+1,h+(s[k]-'0'&&a[i]>k-h-1));
		c[i]=0;
	}
}int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>(s+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	work(1,0);
	cout<<ans<<'\n';
	return 0;
}
