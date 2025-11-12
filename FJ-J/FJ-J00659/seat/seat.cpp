#include<iostream>
using namespace std;
int k[110],n,m,s;
bool kn[15][15];
int dx[]={1,-1,0};
int dy[]={0,0,1};
void dfs(int t,int x,int y){
	kn[1][1]=0;
	for(int i=0;i<3;i++){
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(kn[xx][yy]){
			kn[xx][yy]=0;
			if(t+1==s){
				cout<<yy<<" "<<xx;
				exit(0);
			}
			else dfs(t+1,xx,yy);
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int x=1;x<=n*m;x++){
        cin>>k[x];
	}
    s=k[1];
	for(int i=1;i<n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(k[j]>k[i])
			    swap(k[j],k[i]);
		}
	}
	for(int i=1;i<=n*m;i++){
		if(k[i]==s)
		    s=i;
	}
	for(int x=0;x<=n+1;x++){
		for(int y=0;y<=m+1;y++){
			if(x>=1&&x<=n&&y>=1&&y<=m)
			    kn[x][y]=1;
			else
			    kn[x][y]=0;
		}
	}
	dfs(1,1,1);
	return 0;
}
