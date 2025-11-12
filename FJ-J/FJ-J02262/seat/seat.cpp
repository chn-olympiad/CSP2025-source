#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[225],b[15][15],r,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];sort(a+1,a+n*m+1);
	cnt=n*m;
	for(int i=1;i<=n;i++){
		if(i%2){
			for(int j=1;j<=m;j++){
				b[i][j]=a[cnt];
				cnt--;
			}
		}else{
			for(int j=m;j>=1;j--){
				b[i][j]=a[cnt];
				cnt--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(r==b[i][j]){
				cout<<i<<' '<<j;
				break;
			}
		}
	}
	return 0;
}
