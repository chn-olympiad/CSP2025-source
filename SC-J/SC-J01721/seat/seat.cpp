#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int c;
	int a[101],b[101][101];
	int u=1,q=0;
	int p;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		p=a[i];
	}sort(a,a+1+n,c);
	for(int i=1;i<=n;i++){
		if(u==1){
			for(int j=1;j<=m;j++){
				q++;
				b[i][j]=a[q];
			}
			u=0;
		}else{
			q++;
			b[i][i]=q;
		}
	}
	return 0;
}