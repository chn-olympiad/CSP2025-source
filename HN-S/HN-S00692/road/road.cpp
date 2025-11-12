#include<bits/stdc++.h>
using namespace std;
#define IO(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
const int N =1e4 + 17;
struct II{
	int z,v;
};
int c[17]; 
int n,m,k;
bool b[N];
int A[N][N];
vector<II> a[N];
int l[N];
void p(){
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(A[i][j]<1e9){
				a[i].push_back({j,A[i][j]});
				a[j].push_back({i,A[i][j]});
			}
		}
	}
	b[1]=1;
	for(int x=1;x<n;x++){
	int minn=0x7f7f7f7f,t; 
		for(int i=1;i<=n;i++){
			if(b[i]){
				for(int j=0;j<a[i].size();j++){
					if(a[i][j].v<minn && b[a[i][j].z]==0){
						minn=a[i][j].v;
						t=a[i][j].z;
					}
				}
			}
		}
		ans+=minn;
		b[t]=1;
	}
	printf("%d",ans);
	
}
int main(){
	IO("road");
	memset(A,0x7f,sizeof(A));
	scanf("%d%d%d",&n,&m,&k);
	
	for(int i=1;i<=m;i++){
		int q,z,v;
		scanf("%d%d%d",&q,&z,&v);
		A[z][q]=min(A[z][q],v);
		A[q][z]=min(A[q][z],v);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		
		for(int j=1;j<=n;j++){
			scanf("%d",&l[j]);
		}
		for(int x=1;x<=n;x++){
			for(int y=1;y<x;y++){
				A[x][y]=min(A[x][y],l[x]+l[y]);
				A[y][x]=A[x][y];
			}
		}
	}
	p();
	return 0;
}  
/*
4 4 1 
1 2 3
1 4 5
1 3 6
3 4 7
0 2 3 3 5
*/
