#include<bits/stdc++.h>
using namespace std;
int n,m,s,k=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat3.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n+1][m+1];int b[n*m+1];
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	s=b[1];
	for(int i=1;i<=n*m;i++)
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=b[k++];
		}
	}			
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s==a[i][j]){
			cout<<i<<" "<<j;
			break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
