#include<bits/stdc++.h>
using namespace std;
int n,i,x,a[500010],t,k,j,ans;
struct pcs{
	int l,r;
}f[1000010];
bool cmp(pcs q,pcs b){
	if(q.r<b.r) return 1;
	else if(q.r==b.r&&q.l>b.l)return 1;
	else return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++){
		x=0;
		for(j=i;j<=n;j++){
			x=x^a[j];
			if(x==k) f[++t].l=i,f[t].r=j;
		}
	}
	x=0;
	sort(f+1,f+1+t,cmp);
	for(i=1;i<=t;i++){
		if(f[i].l>x) ans++,x=f[i].r;
	}
	cout<<ans;
	return 0;
}

