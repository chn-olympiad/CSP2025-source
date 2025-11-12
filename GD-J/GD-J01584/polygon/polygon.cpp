#include<bits/stdc++.h>
#define psb push_back
#define fi first
#define se second
#define endl '\n'
using namespace std;
const int N=5005,mod=998244353;
int n,a[N],f[N],mx;
void add(int &a,int b){a+=b;if(a>=mod)a-=mod;}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	sort(a+1,a+1+n);
	f[0]=1;
	int ans=1;
	for(int i=1;i<=n;i++)ans=ans*2%mod;
	add(ans,mod-1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=a[i];j++)add(ans,mod-f[j]);
		for(int j=mx;j>=a[i];j--)add(f[j],f[j-a[i]]);
	}
	cout<<ans<<endl;
	return 0;
}
