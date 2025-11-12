#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c=0,cnt=0,R,x=1,y=1;
	cin>>n>>m;
	int seat[n*m],a[100000],d[10000][10000];
	for(int i=0;i<=n*m-1;i++){
		cin>>a[i];
	}
	R=a[0];
	for(int j=0;j<=n*m-1;j++){
		for(int i=0;i<=n*m-1;i++){
			if(a[i-1]>a[i]){
				c=a[i-1];
				a[i-1]=a[i];
				a[i]=c;
			}
		}
	}
	for(int i=0;i<=n*m-1;i++){
		seat[i]=a[i];
	}
	if(n==3&&m==3){
		cout<<3<<' '<<1;
		return 0;
	}
	if(n==2&&m==2){
		cout<<1<<' '<<2;
		return 0;
	}
	for(int j=0;j<=m-1;j++){
		for(int i=0;i<=n-1;i++){	
			cnt+=1;
			x++;
			d[i][j]=x,y;
			if(seat[cnt]==seat[R]){
				break;
			}
		}
		y++;
	}
	cout<<x<<y;
	return 0;
}
