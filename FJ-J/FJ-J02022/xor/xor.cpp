#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6,MOD=0,inf=0x3f3f3f3f;
int a[N],f[N],p[N],n;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int k;cin>>n>>k;memset(p,0xc0,sizeof(p));p[0]=0;
	for(int i=1;i<=n;i++) cin>>a[i],a[i]^=a[i-1];
	for(int i=1;i<=n;i++) f[i]=max(f[i-1],p[a[i]^k]+1),p[a[i]]=max(p[a[i]],f[i]);
	cout<<f[n]<<endl;
	return 0;
}
