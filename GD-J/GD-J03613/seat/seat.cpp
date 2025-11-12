#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
bool f[107];
int v[107][107];
int dx[]{1,0,-1,0};
int dy[]{0,1,0,1};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%d",&x);
	f[x]=1;
	for(int i=2;i<=n*m;i++){
		scanf("%d",&y);
		f[y]=1;
	}
	int a=0,b=1,dir=-1,sum=0,k=101;
	while(sum<n*m){
		dir=(dir+1)%4;
		if(dir==1||dir==3){
			sum++;
			a+=dx[dir];
			b+=dy[dir];
			k--;
			while(f[k]==0) k--;
			v[a][b]=k;
		}
		else if(dir==0){
			while(a<n){
				sum++;
				a+=dx[dir],b+=dy[dir];
				k--;
				while(f[k]==0) k--;
				v[a][b]=k;
			}
		}
		else{
			while(a>1){
				sum++;
				a+=dx[dir],b+=dy[dir];
				k--;
				while(f[k]==0) k--;
				v[a][b]=k;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(v[i][j]==x){
				cout<<j<<" "<<i;
				return 0; 
			}
		}
	}
	return 0;
}
