//T2(100points)
#include<bits/stdc++.h>
using namespace std;
int a[407];
int c[407];
int ans[50][50];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int r=a[1],cnt=0;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++) c[i]=a[n*m-i+1];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cnt++;
			if(i%2){
				ans[j][i]=c[cnt];
			}
			else if(i%2==0){
				ans[n-j+1][i]=c[cnt];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]==r){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	return 0;
} 
