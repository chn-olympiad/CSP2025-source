#include<bits/stdc++.h>
using namespace std;
int shu,n,m,k,c,bx,by,b=1000000005;
long long num=0;
int a[10015][10015],vis[10015][10015];

struct node{
	int x,y;
};

void db(int x,int y){
	queue<node>q;
	q.push({x,y});
	vis[x][y]=1;
	while(q.size()){
		
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m+k;i++){
		for(int j=1;j<=m+k;j++){
			a[i][j]=1000000005;
		}
	}for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y>>shu;
		if(shu<b){
			b=shu;
			bx=x,by=y;
		}
		a[x][y]=a[y][x]=shu;
	}for(int i=1;i<=k;i++){
		cin>>c;
		a[m+i][m+i]=c;
		for(int j=1;j<=m;j++){
			cin>>c;
			a[m+i][j]=a[j][m+i]=c;
		}
	}db(bx,by);
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
