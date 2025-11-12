#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
int n,m,sum,a[105],b[11][11],cnt,tnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	cnt=a[1];
	sort(a+1,a+1+sum,cmp);
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				tnt++;
				b[i][j]=a[tnt];
				if(b[i][j]==cnt){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				tnt++;
				b[i][j]=a[tnt];
				if(b[i][j]==cnt){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}