#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10010],g,s,f[10010];
int find(int a){
	if(f[a]==a) return a;
	else return find(f[a]);
}
int u(int a,int b){
	f[b]=find(a); 
}
struct st{
	int a,b,q;
}l[1001000];
int cmp(st a,st b){
	return a.q<b.q;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
cin>>n>>m>>k;
for(int i=1;i<=n;i++){
	f[i]=i;
}
for(int i=1;i<=m;i++){
	cin>>l[i].a>>l[i].b>>l[i].q;
}
sort(l+1,l+m+1,cmp);
for(int i=1;i<=k;i++){
	cin>>g;
	for(int j=1;j<=n;j++){
		cin>>g;
	}
}
for(int i=1;i<=m-1;i++){
	if(find(f[l[i].a])!=find(f[l[i].b])){
		u(l[i].a,l[i].b);
		s+=l[i].q;
	}
}
cout<<s;
	return 0;
}
