#include<bits/stdc++.h>
using namespace std;
int q[5000][5000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,con;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>q[i][j];
			if(i==1&&j==1){
				con=q[i][j];
			}
		}
	}
	int t=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(q[i][j]<q[i][j+1]&&j+1<=n){
				swap(q[i][j],q[i][j+1]);
			}else {
				t=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(t==0){
				if(q[i][j]==con){
					cout<<i<<" "<<j;
					break;
				}
			}else{
				if(q[i][j]==con){
					cout<<i+1<<" "<<j;
					break;
				}
			}
		}
	}
	return 0;
}