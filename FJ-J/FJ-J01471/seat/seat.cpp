#include <bits/stdc++.h>
using namespace std;
int cost;
int b[186];
int a[13][13];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>b[i];
	int ok=b[1];
	sort(b+1,b+1+(n*m));
	int index=n*m;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				a[i][j]=b[index--];
				if(a[i][j]==ok){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}else{
			for(int i=n;i>=1;i--){
				a[i][j]=b[index--];
				if(a[i][j]==ok){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}
