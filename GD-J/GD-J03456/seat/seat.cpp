#include <bits/stdc++.h>
using namespace std;

int n,m,k,g[1005],a[15][15];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>g[i];
	int p=g[1],x,y;
	
	sort(g+1,g+n*m+1,cmp);
	
	bool f=0;
	for(int j=1;j<=m;j++){
		if(!f){
			f=1;
			for(int i=1;i<=n;i++){
				a[i][j]=g[++k];
				if(g[k]==p) {cout<<j<<" "<<i;return 0;}
			}
		}else{
			f=0;
			for(int i=n;i>=1;i--){
				a[i][j]=g[++k];
				if(g[k]==p) {cout<<j<<" "<<i;return 0;}				
			}
		}
	}
} 
