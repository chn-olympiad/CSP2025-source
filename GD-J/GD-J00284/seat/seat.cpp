#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int a[20][20];
int b[210];
bool cmp(int a,int b){
	return a>b;
}
void fun(int x,int y,int k){
	a[x][y]=k;
	if(x-1>=1&&a[x-1][y]==0)	fun(x-1,y,k+1);
	if(x+1<=n&&a[x+1][y]==0)	fun(x+1,y,k+1);
	if(y+1<=m&&a[x][y+1]==0)	fun(x,y+1,k+1);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	t=b[1];
	int s;
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[i]==t){
			s=i;
			break;
		}
	}
	fun(1,1,1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==s){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
}
