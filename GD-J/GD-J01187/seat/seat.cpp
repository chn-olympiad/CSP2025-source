#include<bits/stdc++.h>
using namespace std;
const int N=1e1+10;
int a[N][N];
int b[N*N];
int x;
int n,m;
bool cmp(int a,int b){
	return a>b;
}

void print(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}	
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>b[1];x=b[1];
	for(int i=2;i<=n*m;i++){
		cin>>b[i];
	}
	sort(b+1,b+1+n*m,cmp);
	int k=0,l=1;
	while(k<=n*m){
		for(int i=1;i<=n;i++)k++,a[i][l]=b[k];
		l++;
		for(int i=n;i>=1;i--)k++,a[i][l]=b[k];
		l++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==x){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	
	return 0;
}
