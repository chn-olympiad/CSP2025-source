#include<bits/stdc++.h>
using namespace std;
int n,f[100110],m,k,t1,s,r,kl[11],ke[11];
struct e{
	int u,v,w;
};e d[3000100];
bool op(e x,e y){
	return x.w<y.w;	
}
int find(int x){
	if(f[x]==x)return x;
	else{f[x]=find(f[x]);
	return f[x];}
} 
int un(int x,int y){
	x=find(x);y=find(y);
	f[y]=x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>d[i].u>>d[i].v>>d[i].w;
		f[i]=i;
	}
	for(int i=0;i<k;i++){
		cin>>t1;f[n+i]=n+i;
		for(int j=0;j<n;j++){
			cin>>d[i*n+j+m].w;
			d[i*n+j+m].u=i+n;
			d[i*n+j+m].v=j;
		}
	}
	sort(d,d+m+k*n,op);
	for(int i=0;i<m;i++){
		if(find(d[i].u)!=find(d[i].v)){
			un(d[i].u,d[i].v);if(d[i].u>=n){
				if(ke[d[i].u-n]==0){
					ke[d[i].u-n]++;
					kl[d[i].u-n]=d[i].w;
				}else if(ke[d[i].u-n]==1){
					ke[d[i].u-n]++;
					kl[d[i].u-n]=0;
				}
			}s+=d[i].w;r++;if(r==n+k-1)break;
		}
	}
	for(int i=0;i<k;i++){
		s-=kl[i];
	}
	cout<<s;
	return 0;
}

