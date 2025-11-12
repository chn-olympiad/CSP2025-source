#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int seat[100][100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[10001];
	for(int i=1;i<=n*m;i++){
		cin>>a[i]; 
	}
	int R=a[1];
	sort(a+1,a+n*m+1,cmp);

	int p=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				seat[j][i]=a[p];

				p++;
			}
		}else{
			for(int j=n;j>=1;j--){
				seat[j][i]=a[p];

				p++; 
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){

			if(seat[i][j]==R){
				cout<<j<<" "<<i;
				break;
			}
		}

	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}