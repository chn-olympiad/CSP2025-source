#include<bits/stdc++.h>
using namespace std;
const int N=25;
int n,m;
int a[N*N],ma[N][N];
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
//	m=n=10;
//	for(int i=1;i<=n*m;i++)a[i]=i;
	int beg=a[1],o=0;
	stable_sort(a+1,a+1+n*m,cmp);
	for(int j=1;j<=m;j++){
		if(j&1){
			for(int i=1;i<=n;i++)ma[i][j]=a[++o];
		}
		else for(int i=n;i>=1;i--)ma[i][j]=a[++o];
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++)cout<<ma[i][j]<<' ';
//		cout<<'\n';
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ma[i][j]==beg){
				cout<<j<<' '<<i<<'\n';
				return 0;
			}
		}
	}
	return 0;
}
/*
2 2
99 100 97 98
*/