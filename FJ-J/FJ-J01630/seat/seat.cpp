#include<bits/stdc++.h>
using namespace std;
int n,m,a[11][11],cj[101];
int cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>cj[i];
	}
	int ans=cj[1],t=n*m;
	sort(cj+1,cj+t+1,cmp);
	int x=0,y=1,sz=0;
	while(sz<t){
		sz++;
		if(y%2==1){
			if(x!=n){
				x++;
				a[x][y]=cj[sz];
			}else{
				if(x==n){
					y++;
					a[x][y]=cj[sz];
				}
			}
		}else{
			if(y%2==0){
				if(x!=1){
					x--;
					a[x][y]=cj[sz];
				}else{
					if(x==1){
						y++;
						a[x][y]=cj[sz];
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==ans){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}

