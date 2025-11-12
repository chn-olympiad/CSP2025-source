#include<bits/stdc++.h>
using namespace std;
int n,m;
int k[101],c[11][11],ans=1;
bool cmp(int x,int y){
	if(x>y) return 1;
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>k[i];
	}
	k[0]=k[1];
	sort(k+1,k+n*m+1,cmp);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				c[i][j]=k[ans];
				ans++;
			}
		}
		else{
			for(int i=n;i>=1;i--){
				c[i][j]=k[ans];
				ans++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(k[0]==c[i][j]){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
