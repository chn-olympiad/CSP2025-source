#include <bits/stdc++.h>
using namespace std;
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen
int n,m,k,a[500010],s[500010],l=1,r,ans;
struct z{int l,r;}v[10000100];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]^a[i];
	for(int i=1;i<=n;i++) for(int j=i;j<=n;j++)
		if((s[j]^s[i-1])==k) v[++m]={i,j};
	sort(v+1,v+m+1,[](z a,z b){return a.r!=b.r?a.r<b.r:a.l<b.l;});
	for(int i=1;i<=m;i++) {
		if(v[i].l>r) ans++,r=v[i].r;
	}cout<<ans;
}
