#include<bits/stdc++.h>
using namespace std;
long long n,m,k,i,j,p,t;
long long K[11],a[1020];
struct _{long long l,r,t;}s[1100020];
bool S(_ x,_ y){
	if(x.t!=y.t)return x.t<y.t;
	if(x.l!=y.l)return x.l<y.l;
	return x.r<y.r;
}
long long find(long long q){
	if(a[q]==q)return q;
	return a[q]=find(a[q]);
}
void init();
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init();p=i=0;
	while(++i){
		if(p==n-1){cout<<t;return 0;}
		s[i].l=find(s[i].l);
		s[i].r=find(s[i].r);
		if(s[i].l!=s[i].r){
			if(s[i].r>n&&a[s[i].r]==s[i].r)
			t+=K[s[i].r-n];
			else p++;
			t+=s[i].t;
			a[find(s[i].r)]=a[find(s[i].l)];
		}
	}
}
void init(){
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++)
	a[i]=i;
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&s[i].l,&s[i].r,&s[i].t);
		if(s[i].l>s[i].r)swap(s[i].l,s[i].r);
	}
	for(i=1;i<=k;i++){
		scanf("%d",&K[i]);
		for(j=1;j<=n;j++){
			p=m+n*(i-1)+j;
			s[p].l=j;s[p].r=n+i;
			scanf("%d",&s[p].t);
		}
	}
	sort(s+1,s+1+p,S);
	return;
}
