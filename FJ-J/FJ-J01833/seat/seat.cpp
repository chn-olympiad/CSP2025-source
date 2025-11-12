#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101],b[11][11];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int cnt=a[1];
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j%2){
				b[i][j]=a[(j-1)*n+i];
			}else{
				b[i][j]=a[(j-1)*3+n-i+1];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==cnt){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
  return 0;
}
