#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[110];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int R=a[1];
	sort(a+1,a+(n*m)+1,cmp);
/*	for(int i=1;i<=m*n;i++){
		cout<<a[i]<<" ";
	}*/
	for(int j=1;j<=m;j++){
		if(j%2!=0){
			for(int i=1;i<=n;i++){
				if(a[n*(j-1)+i]==R){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[n*j-i+1]==R){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}
