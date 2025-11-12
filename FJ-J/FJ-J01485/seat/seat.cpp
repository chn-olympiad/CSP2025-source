#include<bits/stdc++.h>
using namespace std;
int n,m,a[20][20],b[200],x=1,y=1,z;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>b[i];
	z=b[1];
	sort(b+1,b+n*m+1);
	for(int i=n*m;i>=1;i--){
		a[x][y]=b[i];
		if(y%2==1) x++;
		else x--;
		if(x==n+1||x==0){
			y++;
			if(!x) x=1;
			else x=n;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
				if(a[i][j]==z) cout<<j<<" "<<i;
		}
	}
	return 0;
}
