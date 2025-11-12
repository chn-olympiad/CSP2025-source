#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+7;
int n,m,k;
struct q{
	int x,y,w;
}a[N+N];
int fa[N];
int v[N];
bool cmp(q x,q y){
	return x.w<y.w;
}
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]); 
}
void mer(int x,int y){
	fa[find(x)]=find(y);
}
int lt,rt;
ll sum;
void kra(){
	int cnt=0;
	for(int i=1;i<=m;i++){
		int nx=find(a[i].x);
		int ny=find(a[i].y);
		if(nx!=ny) mer(a[i].x,a[i].y),sum+=a[i].w,cnt++;
		if(cnt==n-1) break;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i].x>>a[i].y>>a[i].w;
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(a+1,a+1+n,cmp);
	kra();
	cout<<sum<<endl;
	return 0;
}
