#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[15][15],n,m,b[105],c;
bool cmp(int a,int b){
	return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>c;
	for(int i=1;i<n*m;i++){
		cin>>b[i];
	}
	b[n*m]=c;
	sort(b+1,b+n*m+1,cmp);
	int x=1,y=0;
	for(int i=1;i<=n*m;i++){
		if(y<=n)y++;
		if(y==n+1){
			y=1;
			x++;
		}
		a[y][x]=b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==c){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
