#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;++i){
		cin >> a[i];
	}
	k=a[1];
	int x=m*n;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n;++i){
		if(i%2!=0){
			for(int j=1;j<=m;++j){
				if(a[x]==k){
					cout << i << " " << j << endl;
					break;
				}
				x--;
			}
		}else{
			for(int j=m;j>=1;--j){
				if(a[x]==k){
					cout << i << " " << j << endl;
					break;
				}
				x--;
			}
		}							
	}	
	return 0;
}
