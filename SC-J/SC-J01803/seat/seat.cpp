#include<bits/stdc++.h> 
using namespace std;
int k[225];
int sp[15][15];
int n,m,po,pi;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>k[i];
	}
	po=k[1];
	sort(k+1,k+(n*m)+1);
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				sp[i][j]=k[pi];
				pi++;
				if(sp[i][j]==po) cout<<j<<' '<<i;
			}
		}
		else
			for(int j=n;j>0;j--){
				sp[i][j]=k[pi];
				pi++;
				if(sp[i][j]==po) cout<<j<<' '<<i;
			}
	}
}