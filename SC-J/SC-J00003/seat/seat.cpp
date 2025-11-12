#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int len=n*m;
	int a[105];
	for(int i=1;i<=len;i++){
		cin>>a[i];
	}
	int s=a[1];
	sort(a+1,a+len+1,cmp);
	int b[15][15];
	int k=1;
	for(int i=1;i<=n;i++){
		if(i%2!=0){
			for(int j=1;j<=m;j++){
				b[i][j]=a[k];
				k++;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				b[i][j]=a[k];
				k++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==s){
				cout<<i<<' '<<j;
				break;
			}
		}
	}
	return 0;
}
