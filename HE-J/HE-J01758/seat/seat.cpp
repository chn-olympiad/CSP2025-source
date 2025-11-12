#include<bits/stdc++.h>
using namespace std;
int seat[21][21];
int num[10000],px[30];
int n,m,a1;
bool cmp(int a,int b){
	return a>b;
}
void ppx(int list){
	for(int x=1;x<=n;x++){
		px[x]=seat[list][x];
	}
	for(int x=n;x>0;x--){
		seat[list][x]=px[n-x+1];
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>num[i];
		if(i==1)a1=num[i];
	}
	
	sort(num+1,num+n*m+1,cmp);

	int js=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			seat[i][j]=num[js];
			js++;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2==0){
				ppx(i);
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(seat[i][j]==a1){
				cout<<i<<' '<<j;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
