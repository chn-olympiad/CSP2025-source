#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10][10];
long long b[103];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int r=b[1];
	sort(b+1,b+n*m+1,cmp);
	long long q=0;
	long long x=1;
	long long y=1;
	long long cnt=0;
	for(int i=1;i<=n*m;i++){
		q=b[i];
		if(y>n){
			y=1;
		}else{
			if(y<=n){
				cnt++;
			}
			if(x<=m){
				cnt++;
			}
			if(cnt==2){
				a[x][y]=q;
				cnt=0;
				y++;
				if(y>n){
					x++;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(r==a[i][j]){
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
