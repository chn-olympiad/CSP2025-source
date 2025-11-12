#include<bits/stdc++.h>
using namespace std;
int n,m,sc[105],R,RANK,seat[105][105];
bool cmp(int q,int r){
	return q>r;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>sc[i];
	}
	R=sc[0];
	//cout<<"CSP-J RP++!!!";
	sort(sc,sc+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(sc[i]==R)RANK=i+1;
	}
	int x=1,y=1;
	for(int k=1;k<=n*m;k++){
		seat[x][y]=k;
		if(x==n&&y%2==1){
			++y;continue;
		}
		if(x==1&&y%2==0){
			++y;continue;
		}
		if(1<=x&&x<n&&y%2==1){
			++x;continue;
		}
		if(1<x&&x<=n&&y%2==0){
			--x;continue;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(seat[i][j]==RANK)cout<<j<<' '<<i<<endl;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<seat[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	return 0;
}
