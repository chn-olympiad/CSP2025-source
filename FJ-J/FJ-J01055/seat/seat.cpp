#include <bits/stdc++.h>
using namespace std;
int mp[15][15],l[105];
int n,m,a=1;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>l[i];
	}
	int ams=l[1];
	sort(l+1,l+n*m+1,cmp);
	if(m%2==1){ 
		for(int x=1;x<m;x+=2){
			for(int y=1;y<=n;y++){
				mp[y][x]=l[a++];
			}
			for(int y=n;y>=1;y--){
				mp[y][x+1]=l[a++];
			}
		}
		for(int y=1;y<=n;y++){
			mp[y][m]=l[a++];
		}
	}else{ 
		for(int x=1;x<=m;x+=2){
			for(int y=1;y<=n;y++){
				mp[y][x]=l[a++];
			}
			for(int y=n;y>=1;y--){
				mp[y][x+1]=l[a++];
			}
		}
		
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==ams) cout<<j<<' '<<i;
		}
	}
	return 0;
}

