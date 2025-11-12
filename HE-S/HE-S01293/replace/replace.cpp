#include<bits/stdc++.h>
using namespace std;
int a=0,b=0,c=0,n,bj=0;
int lst[100001][4];
int as[100001];
bool cmp(int a,int b){
	return a>b;
}
void bve(int x){
	if(x>n+1)return;
	for(int i=x+1;i<=n;i++){
		for(int j=1;j<=4;j++){
			if(j==1){
				a++;
				bve(x+1);
				as[bj]+=lst[x][j];
			}
			if(j==2){
				b++;
				bve(x+1);
				as[bj]+=lst[x][j];
			}
			if(j==3){
				c++;
				bve(x+1);
				as[bj]+=lst[x][j];
			}
			else{
				bve(x+1);
			}
			bj++;
		}
	}
}
int t;
int main(){
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int i=0;i<n;i++){
		cin>>lst[i][1]>>lst[i][2]>>lst[i][3];
	}
		bve(0);
		sort(as,as+100012,cmp);
		cout<<as[0];
	}
}
