#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[110];
int s[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int g=a[1];
	sort(a+1,a+1+n*m,cmp);
	int id=1;
	for(int j=1;j<=m;j++){
		
		if(j%2!=0){
			for(int i=1;i<=n;i++){
				s[i][j]=a[id];
				id++;
			}
		}else{
			for(int i=n;i>=1;i--){
				s[i][j]=a[id];
				id++;
			}
		}
	}
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=m;j++){
			if(g==s[i][j]){
				cout << j << " " << i;
				return 0;
			}
		}	
	}

	return 0;
}
