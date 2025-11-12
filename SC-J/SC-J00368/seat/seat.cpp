#include<bits\stdc++.h>
using  namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[10005],b[101][101],R;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	int num=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[i][j]=a[num];
				num++;
			}	
		}
		else{
			for(int j=n;j>=1;j--){
				b[i][j]=a[num];
				num++;
			}	
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==R){
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}
	
	return 0;
}