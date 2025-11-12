#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int seat_dir[20][20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[110],n,m,xiao_grade;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xiao_grade=a[1];
	sort(a+1,a+n*m+1,cmp);
	int mn=0;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				mn++;
				seat_dir[i][j]=a[mn];
			}
		}
		else{
			for(int i=n;i>=1;i--){
				mn++;
				seat_dir[i][j]=a[mn];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(seat_dir[i][j]==xiao_grade){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
