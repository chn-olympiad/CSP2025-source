#include<bits/stdc++.h>
using namespace std;
int a[110],b[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int p=b[1];
	sort(b+1,b+m*n+1);
	for(int i=1;i<=n*m;i++){
		a[i]=b[m*n+1-i];
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[(i-1)*n+j]==p){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[(i-1)*n+j]==p){
					cout<<i<<' '<<n-j+1;
					return 0;
				}
			}
		}
	}
	return 0;
} 
