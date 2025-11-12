#include <bits/stdc++.h>
using namespace std;
int se[50][50];
int a[300];
bool bijiao(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>a[i];
	int mubiao = a[0];
	sort(a,a+n*m,bijiao);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2 == 0){
			for(int j=n;j>=1;j--){
				se[j][i] = a[cnt];
				cnt++;
			}
		}else{
			for(int j=1;j<=n;j++){
				se[j][i] = a[cnt];
				cnt++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){	
			if(se[i][j] == mubiao){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
