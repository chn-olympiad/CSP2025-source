#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101]={},s;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	int mp[11][11]={},v[11][11]={},x=1,y=1,ans=1;
	for(int i=1;i<=n*m;i++){
		mp[x][y]=a[ans++];
		v[x][y]=1;
		if(1<=x+1&&x+1<=n&&v[x+1][y]==0){
			x++;
		}
		else if(1<=x-1&&x-1<=n&&v[x-1][y]==0){
			x--;
		}
		else if(1<=y+1&&y+1<=m&&v[x][y+1]==0){
			y++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==s){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
