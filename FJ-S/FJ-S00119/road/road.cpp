#include<bits/stdc++.h>
using namespace std;
int n,m,k,c,f[100005],b[10005];
long long sum;
struct SS{
	int v,u,w;
}a[10000005];
bool cmp(SS x,SS y){
	return x.w<y.w;
}
int find(int v){
	if(f[v]==v)return v;
	return f[v]=find(f[v]);
}
bool Union(int v,int u){
	int x=find(v),y=find(u);
	if(x!=y){
		f[v]=u;
		return true;
	}
	return false;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out ","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].v>>a[i].u>>a[i].w;
	}
	for(int i=1;i<=n;i++)f[i]=i;
	if(k==0){
		int h=0;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(Union(a[i].v,a[i].u)){
			sum+=a[i].w;
			if(++h==n-1)break;
		}
	}
	cout<<sum;
	return 0;
		
	}
	int h=0;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(Union(a[i].v,a[i].u)){
			sum+=a[i].w;
			if(++h==n-1)break;
		}
	}
	cout<<sum;
	
	return 0;
}
