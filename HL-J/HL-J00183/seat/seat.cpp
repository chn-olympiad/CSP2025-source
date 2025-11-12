#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001]={0},rseat;
bool isover=false;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	rseat=1;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			rseat++;
		}
	}
	int seat_x=1,seat_y=1,cnt=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m-1;j++){
			seat_y++;
			cnt++;
			if(cnt==rseat){
				cout<<seat_x<<" "<<seat_y;
				return 0;
			}
		}
		seat_x++;
		cnt++;
		if(cnt==rseat){
			cout<<seat_x<<" "<<seat_y;
			return 0;
		}
		for(int j=1;j<=m-1;j++){
			seat_y--;
			cnt++;
			if(cnt==rseat){
				cout<<seat_x<<" "<<seat_y;
				return 0;
			}
		}
		seat_x++;
		cnt++;
		if(cnt==rseat){
			cout<<seat_x<<" "<<seat_y;
			return 0;
		}
	}
	return 0;
}
