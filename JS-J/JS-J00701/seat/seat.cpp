#include<bits/stdc++.h>
using namespace std;
int n,m,score[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x,len=0,seat[n+1][m+1];
	while(len<n*m){
		cin>>x;
		len++;
		score[len]=x;
	}int aim=score[1];
	sort(score+1,score+n*m+1);
	for(int i=1;i<=n;i++){
		seat[i][1]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			if(j%2==0){
				seat[i][j]=j*n-i+1;
			}else{
				seat[i][j]=(j-1)*n+i;
			}
		}
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(score[n*m-seat[i][j]+1]==aim){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
}
