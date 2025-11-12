#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[105];
int mp[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	int small_R=s[1];
	sort(s+1,s+m*n+1);
	int x=1,y=1;
	bool sx=false;
	mp[1][1]=s[m*n];
	for(int i=m*n-1;i>=1;i--){
		if(sx){
			if(x>1){
				x--;
				mp[x][y]=s[i];
			}else if(x==1){
				y++;
				mp[x][y]=s[i];
				sx=false;
			}
		}else{
			if(x<m){
				x++;
				mp[x][y]=s[i];
			}else if(x==n){
				y++;
				mp[x][y]=s[i];
				sx=true;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==small_R){
				cout<<j<<' '<<i<<endl;
				break;
			}
		}
	}
	return 0;
}