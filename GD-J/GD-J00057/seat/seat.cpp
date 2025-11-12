#include<bits/stdc++.h>
using namespace std;
string s;
int a[105],n,m,t,seat_x,seat_y;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		t=a[1];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			int dwnum=(i-1)*n+j;
			if(i%2==1) seat_x=(j-1)%n+1,seat_y=i;
			else seat_x=n-((j-1)%n+1)+1,seat_y=i;
			if(t==a[dwnum]){
				cout<<seat_y<<" "<<seat_x;
				exit(0);
			}
		}
	}
	return 0;
}
