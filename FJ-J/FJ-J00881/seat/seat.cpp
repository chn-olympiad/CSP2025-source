#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],num,b[11][11],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	num=a[1];
	cnt=n*m;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[i][j]=a[cnt];
				if(a[cnt]==num){
					cout<<i<<' '<<j;
					return 0;
				}
				cnt--;
			}
		}else{
			for(int j=n;j>=1;j--){
				b[i][j]=a[cnt];
				if(a[cnt]==num){
					cout<<i<<' '<<j;
					return 0;
				}
				cnt--;
			}
		}
	}
	return 0;
}
