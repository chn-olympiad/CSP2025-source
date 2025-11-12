#include <bits/stdc++.h>
using namespace std;
int a[105],b[15][15];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int sz=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	int cnt=1;
	
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				b[i][j]=a[cnt];
				if(a[cnt]==sz){
					cout<<j<<" "<<i;
					return 0;
				}
				cnt++;
			}
		}else{
			for(int i=n;i>=1;i--){
				b[i][j]=a[cnt];
				if(a[cnt]==sz){
					cout<<j<<" "<<i;
					return 0;
				}
				cnt++;
			}
		}
	}
	return 0;
}
