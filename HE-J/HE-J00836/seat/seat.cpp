#include<bits/stdc++.h>
using namespace std;
const int N=110;
int c[N];
int q[N][N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>c[i];
	}
	int r=c[1];
	sort(c+1,c+n*m+1,greater<int>());
	int x=1,y=1,d=0;
	int k=1;
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			q[i][j]=c[k++];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(q[i][j]==r){
				if(j%2==0){
					cout<<j<<" "<<1+n-i;
				}
				else{
					cout<<j<<" "<<i;
				}
			}
		}
	}
	return 0;
}
