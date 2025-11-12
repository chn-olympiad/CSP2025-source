#include<bits/stdc++.h>
using namespace std;
struct A{
	int u,v,w;
}a[1000050];
int n,m,k,f[1000050],ans,b[10050][10050];
bool cmp(A a,A b){
	return a.w<b.w;
}
int fd(int x){
	if(f[x]==x)return x;
	return f[x]=fd(f[x]);
}
bool add(int x,int y){
	int xx=fd(x),yy=fd(y);
	if(xx==yy){
		return 0;
	}
	else{
		f[yy]=xx;
		return 1;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=0;i<m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	} 
	for(int i=0;i<k;i++){
		cin>>b[i][0];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	sort(a,a+m,cmp);
	for(int i=0;i<m;i++){
		if(add(a[i].u,a[i].v)){
			ans+=a[i].w;
		}
	}
	cout<<ans;
	return 0;
}


