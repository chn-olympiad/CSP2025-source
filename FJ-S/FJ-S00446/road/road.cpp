#include<bits/stdc++.h> 
using namespace std;
long long read(){
	char ch;
	long long ans = 0;
	ch = getchar();
	while(ch<='9'&&ch>='0'){
		ans = ans*10+(ch-'0');
		ch = getchar();
	}
	return ans;
}
struct node{
	long long u,v,w;
}a[2000010];
bool cmp(node p,node q){
	return p.w<=q.w;
}
long long n,m,k,uu,vv,ww,c,fa[10010],aa[1010][1010],b[10010],ans,pp;
long long find(long long f){
	if(f==fa[f])return f;
	fa[f] = find(fa[f]);
	return fa[f];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read();
	m = read();
	k = read();
	memset(aa,0x3f3f3f3f,sizeof(aa));
	for(long long i = 1;i<=m;i++){
		uu = read();
		vv = read();
		ww = read();
		aa[uu][vv] = ww;
		aa[vv][uu] = ww;
	}
	for(long long i = 1;i<=n;i++) fa[i] = i;
	for(long long i = 1;i<=k;i++){
		c = read();
		for(long long j = 1;j<=n;j++) b[j] = read();
		for(long long j = 1;j<=n;j++)for(long long kk = 1;kk<=n;kk++){
			aa[j][kk] = min(b[j]+b[kk],aa[j][kk]);
			aa[kk][j] = aa[j][kk];
		}
	}
	for(long long i = 1;i<=n;i++)for(long long j = 1;j<i;j++){
		pp++;
		a[pp].u = i;
		a[pp].v = j;
		a[pp].w = aa[i][j];
	}
	long long zz = 0;
	sort(a+1,a+pp+1,cmp);
	for(long long i = 1;i<=pp;i++){
		long long p = find(a[i].u);
		long long q = find(a[i].v);
		if(p!=q)fa[q] = p,ans+=a[i].w,zz++;
		if(zz==n-1)break;
	} 
	cout<<ans<<"\n";
}
