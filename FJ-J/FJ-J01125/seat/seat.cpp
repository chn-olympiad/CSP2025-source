#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001][1001],b[1001];
bool f=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>b[(i-1)*m+j];
		}
	}
	int x=b[1];
	sort(b+1,b+1+n*m);
		int i=1;
		int j=1;
	for(int d=n*m;d>=1;d--){
		if(f==0){
			if(j==m){
				a[i][j]=b[d];
				f=!f;
				i++;
			}else{
				a[i][j]=b[d];
				j++;
			}
		}else{
			if(j==1){
				a[i][j]=b[d];
				f=!f;
				i++;
			}else{
				a[i][j]=b[d];j--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==x){
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}
	return 0;
}
