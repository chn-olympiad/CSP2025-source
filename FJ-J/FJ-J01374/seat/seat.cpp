#include<bits/stdc++.h>
using namespace std;
int n,m;
int sum=0;
int a[15][15];
int b[105];
int xr=0,mc=0;
int c=0,r=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			sum++;
			b[sum]=a[i][j];
		}
	}
	xr=a[1][1];
	sort(b+1,b+1+sum,cmp);
	for(int i=1;i<=sum;i++){
		if(b[i]==xr){
			mc=i;
			break;
		}
	}
	c=mc/n;
	if(mc%n!=0) c+=1;
	if(c%2==1) r=mc-n*(c-1);
	else r=n*c-mc+1;
	cout<<c<<' '<<r;
	return 0;
}
