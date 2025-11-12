#include<bits/stdc++.h>
using namespace std;
int n,m,a[10010],c[1001][1001],cnt=1,cj=0;
bool hl=0;
bool kp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	} cj=a[1];
	sort(a+1,a+1+n*m,kp);
	for(int i=1;i<=n;i++){
		if(hl==0){
			for(int j=1;j<=m;j++){
				c[i][j]=a[cnt++];
			}
			hl=1;
		}
		else{
			for(int j=m;j>=1;j--){
				c[i][j]=a[cnt++];
			}
			hl=0;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(c[i][j]==cj) {
				cout<<i<<' '<<j;
				return 0;
			}
	return 0;
}
