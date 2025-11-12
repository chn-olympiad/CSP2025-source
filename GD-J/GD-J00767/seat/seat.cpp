#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15],b[105],op,t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>b[++op];
		}
	}
	t=b[1];
	sort(b+1,b+op+1);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[j][i]=b[op--];
			}
		}
		else{
			for(int j=n;j>=1;j--){
				a[j][i]=b[op--];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==t){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
