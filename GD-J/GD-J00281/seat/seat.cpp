#include<bits/stdc++.h>
using namespace std;
int n,m,b[11][11];
struct p{
	int x,r=0;
}a[110];
bool cmp(p x,p y){
	return x.x>y.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
	}
	a[1].r=1;
	sort(a+1,a+n*m+1,cmp);
	bool t=true;
	int k=1;
	for(int i=1;i<=n;i++){
		if(t){
			for(int j=1;j<=m;j++){
				b[i][j]=a[k].r;
				k++;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				b[i][j]=a[k].r;
				k++;
			}
		}
		t=!t;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==1){
				cout<<i<<' '<<j;
			}
		}
	}
	return 0;
}
