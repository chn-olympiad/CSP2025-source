#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a[100][100];
int b[1000]; 
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2==1){
				a[j][i]=j+(i-1)*n;
			}else{
				a[j][i]=(i-1)*n+(n+1-j);
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
		if(i==1){
			x=b[i];
		}
	}	
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[i]==x){
			x=i;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==x){
				cout<<j<<' '<<i;
			}
		}
	}
	return 0;
}
