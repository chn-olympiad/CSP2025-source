#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],num,bits;
struct node{
	int x;
	int y;
	int score;
}seat[200][200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	memset(seat,0,sizeof(seat));
	memset(a,0,sizeof(a));
	num=bits=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	bits=a[1];
	reverse(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				num++;
				seat[i][j].x=i;
				seat[i][j].y=j;
				seat[i][j].score=a[num];	
//				cout<<seat[i][j].x<<" "<<seat[i][j].y<<" "<<seat[i][j].score<<endl;
			}
		}else{
			for(int j=m;j>=1;j--){
				num++;
				seat[i][j].x=i;
				seat[i][j].y=j;
				seat[i][j].score=a[num];
//				cout<<seat[i][j].x<<" "<<seat[i][j].y<<" "<<seat[i][j].score<<endl;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(seat[i][j].score==bits){
				cout<<j<<" "<<i<<endl;
				return 0;
			}
		}
	}
	return 0;
}
