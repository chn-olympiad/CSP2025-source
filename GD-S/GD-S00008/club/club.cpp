#include<bits/stdc++.h>
#define ll long long
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define tfile(x) freopen(x".in","r",stdin)
#define dtfile(x) freopen(x".in","w",stdout)
using namespace std;
const int N=100005;
int n,m,a[N][3],b[N],o[N],c[3];
ll ans;
void solve(int O=3){
	cin>>n,ans=m=0;
	for(int i=1;i<=n;i++)o[i]=0;
	for(int i=0;i<3;i++)c[i]=0;
	for(int i=1;i<=n;i++)for(int j=0;j<3;j++)cin>>a[i][j];
	for(int i=1;i<=n;i++)for(int j=1;j<3;j++)if(a[i][j]>a[i][o[i]])o[i]=j;
	for(int i=1;i<=n;i++)ans+=a[i][o[i]],c[o[i]]++;
	for(int i=0;i<3;i++)if(c[o[i]]>(n>>1))O=o[i];
	for(int i=1;i<=n;i++)if(o[i]==O)swap(a[i][0],a[i][O]),b[++m]=max(a[i][1],a[i][2])-a[i][0];
	sort(b+1,b+1+m);
	for(int i=(n>>1)+1;i<=m;i++)ans+=b[i];
	cout<<ans<<'\n';
}
int main(){
	file("club");
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;cin>>T;while(T--)solve();
	return 0;
}
