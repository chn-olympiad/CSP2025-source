#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,cnt,a[N],b[N][22],s[N][22];
struct node {
	int l,r;
} t[N],q[N];
inline int check(int l,int r) {
	for(int j=0; j<=20; ++j)
		if(((s[r][j]-s[l][j])&1)!=b[n+1][j]) return 1;
	return 0;
}
inline bool cmp(node x,node y) {
	if(x.r==y.r) return x.l<y.l;
	return x.r<y.r;
}
inline bool cmp2(node x,node y) {
	return x.l<y.l;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1,x; i<=n; ++i) {
		cin>>x;
		int tot=0;
		for(; x; x>>=1) b[i][tot++]=(x&1);
	}
	int tot=0;
	for(; k; k>>=1) b[n+1][tot++]=(k&1);
	for(int j=0; j<=20; ++j)
		for(int i=1; i<=n; ++i)
			s[i][j]=s[i-1][j]+b[i][j];
	for(int i=1; i<=n; ++i) {
		int ans=i-1;
		for(int j=i; j<=n; ++j)
			if(!check(i-1,j)) {
				ans=j;
				break;
			}
		if(ans>=i) t[++cnt].l=i,t[cnt].r=ans;
	}
	int num=0;
	sort(t+1,t+cnt+1,cmp);
	for(int i=1; i<=cnt; ++i)
		if(t[i].r!=t[i+1].r) q[++num].l=t[i].l,q[num].r=t[i].r;
	sort(q+1,q+num+1,cmp2);
	int ans=0,r=0;
	for(int i=1; i<=num; ++i) {
		if(r<q[i].l) {
			ans++;
			r=q[i].r;
		}
	}
	cout<<ans;
}