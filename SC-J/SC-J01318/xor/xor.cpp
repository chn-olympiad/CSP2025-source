#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],cnt,ans=1,p;
long long x[500005];
struct node{
	int c,t;
} b[500005],c[500005];
bool cmp(node x,node y){
	if(x.t==y.t) return x.c>y.c;
	return x.t<y.t;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[i]=x[i-1]^a[i];
	}
	int l=1,r=1;
	while(l<=r&&l<=n){
		if(r>n){
			l++;
			r=l;
			if(l>n) break;
		}
		if(int(x[r]^x[l-1])==k){
			b[++cnt].c=l;
			b[cnt].t=r;
			l++;
			r=l;
		}else{
			r++;
		}
	}
	sort(b+1,b+cnt+1,cmp);
	c[++p].c=b[1].c;
	c[p].t=b[1].t;
	for(int i=2;i<=cnt;i++){
		if(b[i].c>c[p].t){
			c[++p].c=b[i].c;
			c[p].t=b[i].t;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}