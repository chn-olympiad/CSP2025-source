#include<bits/stdc++.h>
using namespace std;
int n,m,a[50][50],a1[2500];
bool v=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a1[i];
	}
	int ans=a1[1];
	sort(a1+1,a1+n*m+1);
	int x=1,y=1;
	for(int i=n*m;i>=1;i--){
		if(x<n&&y%2||x>1&&y%2==0){
			if(v){
				a[x][y]=a1[i];
				x++;
			}
			else{
				a[x][y]=a1[i];
				x--;
			}
		}
		else{
			if(y%2==0){
				a[x][y]=a1[i];
				y++;
				x=1;
				v=1;
			}
			else{
				a[x][y]=a1[i];
				y++;
				x=n;
				v=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==ans)cout<<j<<" "<<i;
		}
	}
	return 0;
}
