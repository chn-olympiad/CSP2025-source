#include<bits/stdc++.h>
using namespace std;

const int N=10; 

int n,m;
int a[N*N+10];
int g[N+10][N+10];

bool cmp(int x,int y){
	if(x>y)	return true;
	else	return false;
}

int sum,d;
int f(int x,int y,int k){
	if(sum==(n*m)+1){
		
	}else{
		if(x+1<=n&&g[x+1][y]==0){
			g[x][y]=a[k];
			return f(x+1,y,++k);
			sum++;
		}else if(x-1>=1&&g[x-1][y]==0){
			g[x][y]=a[k];
			return f(x-1,y,++k);
			sum++;
		}else if(y+1<=m&&g[x][y+1]==0){
			g[x][y]=a[k];
			return f(x,y+1,++k);
			sum++;
		}else if(y-1<=m&&g[x][y-1]==0){
			g[x][y]=a[k];
			return f(x,y-1,++k);
			sum++;
		}
	}
} 

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)	cin>>a[i];
	
	int d=a[1];
	sort(a+1,a+n*m+1,cmp);
	
	f(1,1,1);
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(d==g[i][j]){
				cout<<j<<" "<<i;
				return 0;
			}	
		}
	}
	
	cout<<1<<" "<<m;
	
	return 0;
}
