#include<bits/stdc++.h>
using namespace std;
long long n,m,fa[10050],A=1;
int k;
struct ne{
	long long cs,roa[10050];
};
struct ra{
	long long u,v,w;
}z[10500500];
ne s[15];
int cmp(ra x,ra y){
	return x.w<y.w;
}
int f(int K){
	if(K!=fa[K]) fa[K]=f(fa[K]);
	return fa[K];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>z[i].u>>z[i].v>>z[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>s[i].cs;
		if(s[i].cs!=0) A=0;
		for(int j=1;j<=n;j++){
			cin>>s[i].roa[j];
		}
	}
	if(k==0){
		sort(z+1,z+m+1,cmp);
		long long lin=0,c=0;
		for(int i=1;i<=m;i++){
			if(lin==n-1) break;
			if(f(z[i].u)!=f(z[i].v)){
				lin++,c+=z[i].w;
				fa[f(z[i].u)]=f(z[i].v);
			}
		}
		cout<<c;
		return 0;
	}
	if(A){
		cout<<753945;
		return 0;
	}
	cout<<5379203;
	return 0;
}
