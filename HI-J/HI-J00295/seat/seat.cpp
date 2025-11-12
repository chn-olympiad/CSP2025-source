#include<bits/stdc++.h>
using namespace std;
int a[110],mp[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int temp=a[1]; int x,y;
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			if(temp==a[j*n+i]){
				x=i,y=j+1;
				if(y%2==0){
					x=n-x+1;
				}
				cout<<y<<' '<<x;
				return 0;
			}
		}
	}
	return 0;
} 
