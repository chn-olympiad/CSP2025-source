#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,z=0,g=1;
	cin>>n>>m;
	int b[n*m+5],a[n+1][m+1];
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	z=b[1];
	sort(b+1,b+(n*m)+1);
	for(int i=n;i>=1;i--){
		for(int j=m;j>=1;j--){
			a[i][j]=b[g];
			g++;
			if(a[i][j]==z){
				cout<<i<<" "<<j;
			}
		}
	}
}