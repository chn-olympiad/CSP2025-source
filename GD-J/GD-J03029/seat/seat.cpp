#include <bits/stdc++.h>
using namespace std;
int seat[105][105],n,m,cnt;
int a[205];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				cnt++;
				seat[i][j]=cnt;
			}
		}else{
			for(int j=n;j>=1;j--) {
				cnt++;
				seat[i][j]=cnt;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+1+n*m);int p=0; 
	for(int i=1;i<=n*m;i++){
		if(a[i]==r) p=n*m-i+1;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(seat[i][j]==p){
				cout<<i<<" "<<j<<"\n";
				return 0;
			}
		}
	}
	return 0;
}
