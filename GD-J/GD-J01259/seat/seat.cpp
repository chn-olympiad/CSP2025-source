#include<bits/stdc++.h>
using namespace std;
int a[1010];
int n,m;
int main(){
	freopen("E:GD-J01259/seat/seat.in","r",stdin);
	freopen("E:GD-J01259/seat/seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int y=a[1];
	sort(a+1,a+1+n*m);
	int cnt=0;
	for(int i=n*m;i>=1;i--){
		cnt++;
		if(a[i]==y)break;
	}
	int x;
	x=1;
	y=1;
	int u=0;
	cnt--;
	while(cnt>0){
		cnt--;
		if(u==0){
			x++;
			if(x==n){
				u=1;
			}
		}
		else if(u==1){
			y++;
			u=2;
		}
		else if(u==2){
			x--;
			if(x==1){
				u=3;
			}
		}
		else{
			y++;
			u=0;
		}
	}
	cout<<y<<' '<<x;
	return 0;
}
