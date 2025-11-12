#include<bits/stdc++.h>
using namespace std;
long long f[10001],b1[11],n,m,k,s;
struct c1{
	long long u,v,w;
}a[2000001];
long long fd(long long x){
	if(f[x]==x)return x;
	return f[x]=fd(f[x]);
}
bool mg(long long x,long long y){
	x=fd(x);
	y=fd(y);
	if(x!=y){
		f[y]=x;
		return 1;
	}
	return 0;
}
bool cc(c1 a,c1 b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=n;i++)f[i]=i;
		for(int i=1;i<=m;i++){
			cin>>a[i].u>>a[i].v>>a[i].w;
		}
		sort(a+1,a+m+1,cc);
		for(int i=1;i<=m;i++){
			if(mg(a[i].u,a[i].v)){
				s+=a[i].w;
			}
		};
		cout<<s;
	}
	else{
		for(int i=1;i<=n;i++)f[i]=i;
		for(int i=1;i<=m;i++){
			cin>>a[i].u>>a[i].v>>a[i].w;
		}
		for(int i=1;i<=k;i++){
			int b,bb;
			cin>>b;
			for(int j=1;j<=n;j++){
				cin>>b1[j];
				if(b1[j]==0)bb=j;
			}
			for(int j=1;j<=n;j++){
				if(bb==j)continue;
				m++;
				a[m].u=bb;
				a[m].v=j;
				a[m].w=b1[j];
			}
		}
		sort(a+1,a+m+1,cc);
		for(int i=1;i<=m;i++){
			if(mg(a[i].u,a[i].v)){
				s+=a[i].w;
			}
		};
		cout<<s;
	}	
	return 0;
} 

