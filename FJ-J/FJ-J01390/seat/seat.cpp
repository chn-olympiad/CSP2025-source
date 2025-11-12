#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>r;
	a[1]=r;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			for(int j=1;j<=m;j++){
				if(i<=j*n){
					if(j%2!=0)cout<<j<<' '<<i-(j-1)*n;
					if(j%2==0)cout<<j<<' '<<n-(i-(j-1)*n)+1;
					return 0;
				}
			}
			
		}
		
	}
	return 0;
}
