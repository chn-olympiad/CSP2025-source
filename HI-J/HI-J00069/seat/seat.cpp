#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[20][20],b[10010],c[10],d[10010],cnt=0; 

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	cnt = n*m;
	for(int i=1;i<=cnt;i++){
		cin >> b[i];
	} 
	c[1] = b[1];
	sort(b+1,b+1+cnt);
	for(int i=1;i<=cnt;i++) d[i] = b[cnt-i+1];
	
	for(int i=1;i<=n;i++){
		if(i%2!=0){
			for(int j=1;j<=m;j++){
				a[i][j] = d[(i-1)*m+j];
				if(a[i][j]==c[1]){
					cout << i << " "<< j;
					return 0;
				}
			}
		}
		else{
			for(int j=m;j>=1;j--){
				a[i][j] = d[(i-1)*m+m-j+1];
				if(a[i][j]==c[1]){
					cout << i << " "<< j;
					return 0;
				}
			}
		}
	}
	
	return 0;
} 
