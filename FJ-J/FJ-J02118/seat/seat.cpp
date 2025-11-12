#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[15][15],b[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	int maxn=0;
	int sum=a[1][1];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				for(int h=1;h<=n;h++){
					maxn=max(a[k][h],maxn);
				}
			}
			b[i][j]=maxn;
			for(int z=1;z<=m;z++){
				for(int y=1;y<=n;y++){
					if(a[z][y]==maxn){
						a[z][y]=0;
						break;
					}
				}
			}
			maxn=0;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==sum){
				if(i%2==0){
					if(j==1){
						cout<<i<<" "<<n;
						break;
					}	
					else if(j==n){
						cout<<i<<" "<<1;
						break;
					}cout<<i<<" "<<n-j+1;
					break;
				}else{
					if(j==1){
						cout<<i<<" "<<j;
						break;
					}else if(j==n){
						cout<<i<<" "<<n;
						break;
					}cout<<i<<" "<<n-j+1;
					break;
				}
			}
		}
	}
	return 0;
}
