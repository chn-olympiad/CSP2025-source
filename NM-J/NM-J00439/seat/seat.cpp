#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int map[20][20];
	int n,m;
	cin>>n>>m;
	int ji;
	int R;
	priority_queue<int> sum;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>ji;
			if(i==1&&j==1){
				R=ji;
			}
			sum.push(ji);
		}
	}
	int x,y;
	x=1;
	y=1; 
	int d=0;
	while(1){
		if(d%4==0&&x<=n){
			map[x][y]=sum.top();
			if(sum.top()==R){
				cout<<y<<" "<<x;
				return 0;
			}
			sum.pop();
			if(x==n){
				d++;
				continue;
			}
			x++;
		}
		if(d%4==1){
			y++;
			d++;
		}
		if(d%4==2&&x>=1){
			map[x][y]=sum.top();
			if(sum.top()==R){
				cout<<y<<" "<<x;
				return 0;
			}
			sum.pop();
			if(x==1){
				d++;
				continue;
			}
			x--;
		}
		if(d%4==3){
			y++;
			d++;
		}
	}
	return 0;
}
