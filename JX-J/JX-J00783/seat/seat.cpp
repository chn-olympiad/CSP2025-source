#include<bits/stdc++.h>
using namespace std;
int a[110],b[110];
int s[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>b[i];
	}
	int f=b[1];
	sort(b,b+n*m+1);
	int k=1;
	for(int i=m*n;i>=1;i--){
		a[k]=b[i];
		k++;
	}
	int num=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				s[i][j]=a[num];
				num++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				s[i][j]=a[num];
				num++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s[i][j]==f){
				cout<<i<<' '<<j;
			}
		}
	}
	return 0;
}
