#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n,m;
int a[105];
int now=0;
int p=0;
int t[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[++p];
		}
	}	
	now=a[1];
	sort(a+1,a+p+1,greater<int>());
	p=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				t[j][i]=a[++p];
			}
		}else{
			for(int j=n;j>=1;j--){
				t[j][i]=a[++p];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(t[i][j]==now){
				cout<<j<<' '<<i<<'\n';
				return 0;
			}
		}
	}
	return 0;
}  
