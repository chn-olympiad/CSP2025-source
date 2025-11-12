#include <bits/stdc++.h>
using namespace std;
int n,m;
int cj;
int a[1000];
int ma[100][100];
bool cmp(int a,int b){
	if(a!=b) return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++){
		cin>>a[i];
	}
	cj=a[1];
	sort(a+1,a+n*m,cmp);
	int u=1,v=1;
	for(int i=1; i<=n*m; i++){
		if(ma[u][v]==0){
			ma[u][v]=a[i];
		}
		if(u!=n&&v%2==1){
			u++;
			continue;
		}else if(u==n&&v%2==1){
			v++;
			continue;
		}
		if(u!=1&&v%2==0){
			u--;
			continue;
		}else if(u==1&&v%2==0){
			v++;
			continue;
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(ma[i][j]==cj){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
