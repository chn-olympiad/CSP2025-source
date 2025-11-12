#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	int cj=a[1][1],pm=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1&&j==1)continue;
			if(a[i][j]>cj)pm++;
		}
	}
	int c=(pm-1)/n+1;
	int r=(c%2==1?(pm%n==0?n:pm%n):n-(pm%n==0?n:pm%n)+1);
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
