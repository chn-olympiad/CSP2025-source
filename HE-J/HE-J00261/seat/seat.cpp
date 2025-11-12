#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	int n,m;
	cin>>n>>m;
	int c[105];
	int s[15][15];
	for(int i=1;i<=n*m;i++){
		cin>>c[i];
	}
	int str=c[1];
	int h=0;
	sort(c+1,c+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				h++;
				s[i][j]=c[h];
			}
		}
		else{
			for(int j=n;j>=1;j--){
				h++;
				s[i][j]=c[h];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==str){
				cout<<i<<' '<<j;
			}
		}
	}
	return 0;
}
