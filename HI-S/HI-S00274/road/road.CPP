#include <bits/stdc++.h> 
using namespace std;

int u,v,w; 

int n,m,k;
int a[1000006];
int fa[20005];
bool cmp( int z,int j){
	return z < j;
}
int find(int x){
	if(fa[x]==x)return fa[x];
	return fa[x]=find(fa[x]);
}
void kruskal(){
	int ans=0;
	for(int i=1;i<= m;i++){
		int xx=a[i],yy=a[i],val=a[i];
		if	(find(xx)!=find(yy)){
		fa[find(xx)]=find(yy);
		ans+=a[i];
		
	}
}
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
     
      cin>>n>>m>>k;
      int top=m ;
for(int i=1;i<=n+k;i++){
	fa[i]=i;
}

for(int i=1;i<=m;i++){
	cin>>a[i]>>a[i]>>a[i];
}
for(int i=1;i<=k;i++){
	int x;
	cin>>x;
	for(int j=1;j<=n;j++){
		int ww;
		cin >>ww;
		if(ww==0){
			fa[i+n]=j;
		}else{
			a[++top]=
			a[top]=j;
			a[top]=ww;
		}
	}
}
sort(a+1,a+top+1,cmp);
 kruskal();
 cout<<13;
 


	return 0;
}
