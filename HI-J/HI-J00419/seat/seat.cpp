#include <bits/stdc++.h>
using namespace std;
long long n,m,a[105],b[15][15],r,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	r=a[1];
	cnt=1;
	sort(a+1,a+n*m+1);
	for(int i=n;i>=1;i--){
		if(i%2!=0){
			for(int j=m;j>=1;j--){
				b[i][j]=a[cnt];
				cnt++;
			}
		}
		if(i%2==0){
			for(int j=1;j<=m;j++){
				b[i][j]=a[cnt];
				cnt++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(i%2!=0){
			for(int j=1;j<=m;j++){
			}
			
		}
		if(i%2==0){
			for(int j=m;j>=1;j--){
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(i%2!=0){
			for(int j=1;j<=m;++j){
				if(b[i][j]==r){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		if(i%2==0){
			for(int j=m;j>=1;j--){
				if(b[i][j]==r){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
