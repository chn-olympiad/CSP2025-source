#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,rf;
int a[20][20],fen[110];
bool gz(int x,int y) {
	return x>y;
}
void check(int i,int j) {
	if((i%2!=0 and j+1>m) or (i%2==0 and j-1<1)) {
		i++;
	} 
			
}
int main() {
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int cnt=0;
	for(i=1; i<=n; i++) {
		for(j=1;j<=m;j++) {
			cnt++;
			cin>>fen[cnt];
		}	
	}
	rf=fen[1];
	i=1;
	j=1;
	while(i!=n) {		
		fen[cnt]=a[i][j];
		cnt--;		
		if(a[i][j]==rf) {
			cout<<i<<" "<<j;
			break;
		}
		check(i,j);
		if(i%2!=0) j++;
		if(i%2==0) j--;	
	}
	return 0;
}
