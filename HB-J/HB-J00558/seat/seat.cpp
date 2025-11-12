#include<bits/stdc++.h>
using namespace std;
int n,m,x,li[111],re[20][20];
int cmp(int a,int b){
	if(a>b){
		return 1;
	}
	return 0;
}
void sea(int i,int j,int c){
	re[i][j]=li[c];
	if(re[i][j]==x){
		cout<<i+1<<" "<<j+1;
	}
	if(re[i][j+1]==0 && j+1<=n-1){
		sea(i,j+1,c+1);
	}else if(re[i][j-1]==0 && j-1>=0){
		sea(i,j-1,c+1);
	}else if((j==n-1 || j==0) && i+1<=m){
		sea(i+1,j,c+1);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=0;i<n*m;i++){
		cin>>li[i];
	}
	x=li[0];
	sort(li,li+n*m,cmp);
	sea(0,0,0);
	return 0;
}
