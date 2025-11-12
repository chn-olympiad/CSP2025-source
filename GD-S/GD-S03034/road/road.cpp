#include <bits/stdc++.h>
using namespace std;
int n,m,k,b[10005][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z); 
		b[x][y]=z;
		b[y][x]=z;
	}
	while(true){
		
	}
	return 0;
} 

