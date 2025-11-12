#include<bits/stdc++.h>
using namespace std;
int n,m,r,c;
int a[105],goal=0;
int b[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)goal=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	int chuli=1;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				b[i][j]=a[chuli++];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==goal){
				if(i%2==1){
					r=i,c=j;
					break;
				}
				else {
					r=i,c=n-j+1;
					break;
				}
			}
		}
	}
	cout<<r<<" "<<c;
	return 0;
}
