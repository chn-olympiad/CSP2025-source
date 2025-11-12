#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[15][15];
int k=1,e=0,s=0;
bool cmp(int a,int b){
	return a>b;
}
void px(int y,int x,int fx){
    if(k==s){
    	b[y][x]=a[k];
    	return ;
	} 
	b[y][x]=a[k];
	k++;
    if(fx==1){
		if(b[y+1][x]=='*'){
			e=1;
			px(y,x+1,2);
		}
		else px(y+1,x,1);
	}
	if(fx==2){
		if(e==1) px(y-1,x,3);
    	if(e==3) px(y+1,x,1);
	}
	if(fx==3){
	    if(b[y-1][x]=='*'){
			e=3;
			px(y,x+1,2);
		}
		else px(y-1,x,3);
	}
}
int main(){
	int n,m,v=0;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	v=a[1];
	for(int i=1;i<=n;i++){
		b[i][0]='*';
		b[i][m+1]='*';
	}
	for(int i=1;i<=m;i++){
		b[0][i]='*';
		b[n+1][i]='*';
	}
	sort(a+1,a+s+1,cmp);
	px(1,1,1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==v){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	} 
	return 0;
}
