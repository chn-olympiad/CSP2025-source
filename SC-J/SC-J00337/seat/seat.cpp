#include<bits/stdc++.h>
using namespace std;
int a[105],num[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	int cnt=1;
	for(int j=1;j<=m;j++){
		if(j%2){
			for(int i=1;i<=n;i++){
				num[i][j]=a[cnt];
				cnt++;
			}
		}
		else{
			for(int i=n;i>0;i--){
				num[i][j]=a[cnt];
				cnt++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(num[i][j]==t){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}