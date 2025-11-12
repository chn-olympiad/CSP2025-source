#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[1000005],a[10005][10005],b[10005],s;
struct dl{
	int u,v,w;
}x[10005];
bool cmp(dl a,dl b){
	return a.w<b.w;
}
int fa(int a){
	if(!b[a])return a;
	b[a]=fa(b[a]);
	return b[a];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>x[i].u>>x[i].v>>x[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	if(k==0){
		sort(x+1,x+m+1,cmp);
		for(int i=1,j=0;i<=m,j<n;i++)
			if(fa(x[i].u)!=fa(x[i].v)){
				s+=x[i].w;j++;
				b[max(fa(x[i].u),fa(x[i].v))]=min(fa(x[i].u),fa(x[i].v));
			}
		cout<<s;
	}
	return 0;
}
