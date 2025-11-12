#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k;
struct G{
	int u,v,w;
}a[1000010];
bool cmp(G x,G y){
	return x.w<y.w;
}
int b[10010];
int Find(int x){
	if(b[x]==x)return x;
	return b[x]=Find(b[x]);
}
void hb(int x,int y){
	b[Find(x)]=Find(y);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int i;
	for(i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	long long ans=0;
		sort(a+1,a+1+m,cmp);
		for(i=1;i<=n;i++)b[i]=i;
		for(i=1;i<=m;i++){
			int x=a[i].u,y=a[i].v,ww=a[i].w;
			if(Find(x)!=Find(y)){
				ans+=ww;
				hb(x,y);
			}
		}
	cout<<ans;
	return 0;
}
