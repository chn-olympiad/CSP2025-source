#include<bits/stdc++.h>
using namespace std;
bool sttt;
const int N=2e6+10;
int n,k;
int f[N],mx[N],a[N];
bool eddd;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],a[i]^=a[i-1];
	memset(mx,-0x3f,sizeof mx);
	mx[0]=0;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		f[i]=max(f[i],mx[a[i]^k]+1);
		mx[a[i]]=max(mx[a[i]],f[i]);
	}
	cout<<f[n]<<"\n";
	cerr<<(&eddd-&sttt)*1.0/1024/1024<<"\n";
	return 0;
}
