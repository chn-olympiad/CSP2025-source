#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k=n*m-1,c,r;
	cin >> n >> m;
	int a[n][m],b[n*m];
	for(int i=0;i<n*m;i++){
		cin >> b[i];
	}
	int q=b[0];
	sort(b,b+n*m-1);
	for(int i=0;i<n;i++){
		if(i%2==0){
			for(int j=0;j<m;j++){
				a[i][j]=b[k];
				k--;
				if(q==a[i][j]){
					c=i;
					r=j;
					break;
				}
			}
		}
		else{
			for(int j=m-1;j>=0;j--){
				a[i][j]=b[k];
				k--;
				if(q==a[i][j]){
					c=i;
					r=j;
					break;
				}
			}
		}
	}
	cout << c << r;
	return 0;
}
