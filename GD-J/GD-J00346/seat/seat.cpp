#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
	return a>b; 
}

int seat[15][15],stu[120];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	int cr=n*m;
	int p;
	for(int i=1;i<=cr;i++){
		cin>>stu[i];
		if(i==1) p=stu[i];
	}
	sort(stu+1,stu+cr+1,cmp);
	int sur=1;
	for(int j=1;j<=m;j+=2){
		for(int i=1;i<=n;i++){
			seat[i][j]=stu[sur];
			sur++;
		}
		sur+=n;
	}
	sur=n+1;
	for(int j=2;j<=m;j+=2){
		for(int i=n;i>0;i--){
			seat[i][j]=stu[sur];
			sur++;
		}
		sur+=n;
	}
	/*-----debugStarting-----
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<seat[i][j]<<' ';
		}
		puts(""); 
	}
	-----debugEnding-----*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(seat[i][j]==p){
				cout<<j<<' '<<i;
				break;
			}
		}
	}
	return 0;
}

