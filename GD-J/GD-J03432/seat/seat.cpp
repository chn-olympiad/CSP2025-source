#include<bits/stdc++.h>
using namespace std;
int n,m,z;
int a[101],v[101][101];
int main(){
	freopen("seat.in","r",stdin);	
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) z=a[i];
	}
	sort(a+1,a+(n*m)+1);
	int maxn=(n*m);
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(j%2==1){
				v[i][j]=a[maxn];
				maxn--;
			}else{
				v[n-i+1][j]=a[maxn];
				maxn--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(v[i][j]==z){
				cout<<j<<" "<<i;
				return 0;	
			}
		}
	}
	return 0;
} 
