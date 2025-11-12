#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N],b[N][N],r,n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int ji=n*m;
	for(int i=1;i<=ji;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+ji);
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				b[i][j]=a[ji];
				ji--;
				if(b[i][j]==r){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(int j=1;j<=n;j++){
				b[i][j]=a[ji];
				ji--;
				if(b[i][j]==r){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
