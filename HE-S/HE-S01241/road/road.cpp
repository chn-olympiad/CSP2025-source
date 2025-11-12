#include <bits/stdc++.h>
using namespace std;
int n,m,k,cnt,vis[10101][11011][2],top,top2,vis2[10101];
struct node{
	int a,b,c,t;
}a[1100011];
struct node3{
	int k,y;
};
struct node2{
	int c;
	node3 x[10001];
}b[11];
bool cmp(node a,node b){
	return a.c<b.c;
}
bool cmp2(node2 a,node2 b){
	return a.x<b.x;
}
bool cmp3(node3 a,node3 b){
	return a.k<b.k;
}
void dfs(int f,int x,int c){
	for(int i=1;i<top;i++){
		if((a[i].a!=f||a[i].a!=x)&&(a[i].b!=f||a[i].b!=x)){
			if(a[i].a==x){
				if(vis[a[i].b][f][1]==0){
					vis[a[i].b][f][1]=1;
					vis[f][a[i].b][1]=1;
					vis[a[i].b][f][2]=a[i].c+c;
					vis[f][a[i].b][2]=a[i].c+c;
				}else{
					if(vis[a[i].b][f][2]>a[i].c+c){
						vis[a[i].b][f][2]=a[i].c+c;
						vis[f][a[i].b][2]=a[i].c+c;
					}
				}
			}else if(a[i].b==x){
				if(vis[a[i].a][f][1]==0){
					vis[a[i].a][f][1]=1;
					vis[f][a[i].a][1]=1;
					vis[a[i].a][f][2]=a[i].c+c;
					vis[f][a[i].a][2]=a[i].c+c;
				}else{
					if(vis[a[i].a][f][2]>a[i].c+c){
						vis[a[i].a][f][2]=a[i].c+c;
						vis[f][a[i].a][2]=a[i].c+c;
					}
				}
			}else if(a[i].b==f){
				if(vis[a[i].a][x][1]==0){
					vis[a[i].a][x][1]=1;
					vis[x][a[i].a][1]=1;
					vis[a[i].a][x][2]=a[i].c+c;
					vis[x][a[i].a][2]=a[i].c+c;
				}else{
					if(vis[a[i].a][x][2]>a[i].c+c){
						vis[a[i].a][x][2]=a[i].c+c;
						vis[x][a[i].a][2]=a[i].c+c;
					}
				}
			}else if(a[i].a==f){
				if(vis[a[i].b][x][1]==0){
					vis[a[i].b][x][1]=1;
					vis[x][a[i].b][1]=1;
					vis[a[i].b][x][2]=a[i].c+c;
					vis[x][a[i].b][2]=a[i].c+c;
				}else{
					if(vis[a[i].b][x][2]>a[i].c+c){
						vis[a[i].b][x][2]=a[i].c+c;
						vis[x][a[i].b][2]=a[i].c+c;
					}
				}
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	top=n+1,top2=n+1;
	for(int i=1;i<=m;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i].c;
		for(int j=1;j<=n;j++){
			cin>>b[i].x[j].k;
			b[i].x[j].y=j;
		}
	}	
	sort(b+1,b+k+1,cmp2);
	for(int i=1;i<=n;i++){
		sort(b[i].x+1,b[i].x+n+1,cmp3);
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			a[top].a=top2,a[top].b=b[i].x[j].y,a[top].c=b[i].x[j].k,a[top].t=b[i].c;
			vis2[top2]=1;
			top++;
		}
		top2++;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<top;i++){
		if(a[i].a!=a[i].b){
			if(vis[a[i].a][a[i].b][1]==0){	
				vis[a[i].a][a[i].b][1]=1;
				vis[a[i].b][a[i].a][1]=1;
				vis[a[i].a][a[i].b][2]=a[i].c;
				vis[a[i].b][a[i].a][2]=a[i].c;
				if(vis2[a[i].a]==1){
					vis2[a[i].a]=0;
					vis[a[i].a][a[i].b][2]+=a[i].t;
				    vis[a[i].b][a[i].a][2]+=a[i].t;
				}
			}else{
				if(vis2[a[i].a]==1){
				    if(a[i].c+a[i].t<vis[a[i].b][a[i].a][2]){
						vis[a[i].a][a[i].b][2]=a[i].c+a[i].t;
					    vis[a[i].b][a[i].a][2]=a[i].c+a[i].t;  
					    vis2[a[i].a]=0;
						vis[a[i].a][a[i].b][2]+=a[i].t;
					    vis[a[i].b][a[i].a][2]+=a[i].t;
					    
					}
				}
				
			}
			dfs(a[i].a,a[i].b,a[i].c);	
		}
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<vis[i][j][2]<<" ";
		}
		cout<<endl;
	}	
	for(int i=1;i<=n;i++){
		cnt+=vis[i][i][2];
	}
	
	
	return 0;
}
