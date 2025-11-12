#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
struct aaa{
	int num;
	int fen;
};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	aaa b[n*m+1];
	int a[n+1][m+1];
	for(int i=1;i<=n*m;i++){
		cin>>b[i].fen;
		b[i].num=i;
	}
	for(int i=1;i<=n*m;i++){
		int g=i;
		for(int j=i+1;j<=n*m;j++){
			if(b[g].fen>b[j].fen){
				int fen1=b[g].fen;
				b[g].fen=b[j].fen;
				b[j].fen=fen1;
				int num1=b[g].num;
				b[g].num=b[j].num;
				b[j].num=num1;
			}
		}
	}
	int sum=1,sss=n*m;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			sum=1;
			while(sum<=n){
				a[sum][i]=b[sss].num;
				sum++;
				sss--;
			}
		}
		else{
			sum=n;
			while(sum>=1){
				a[sum][i]=b[sss].num;
				sum--;
				sss--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==1){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
} 
