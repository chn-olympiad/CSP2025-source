#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[15][15];
int mark[110];
int high=1;
int fx,fy;


int main(void){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>mark[1];
	int i,j;
	for(i=2;i<=n*m;i++){
		cin>>mark[i];
		if(mark[i]>mark[1]){
			high++;
		}
	}
	int x,y;
	x=high/n;
	y=high%n;
	if(y==0){
		x--;
		y=n;
	}
	if(x%2==0){
		fx=x+1;
		fy=y;
	}else{
		fx=x+1;
		fy=n-y+1;
	}
	cout<<fx<<' '<<fy<<'\n';
	//cout<<x<<' '<<y;
	return 0;
}
