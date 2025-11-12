#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],k=1;
int xiao_r;
bool cmp(int a,int b){
	if(a>b)	return true;
	else return false;
}

int fr[5]={0,-1,0,1,0};
int fc[5]={0,0,-1,0,1};
int seat[20][20]; 
void dfs(int r,int c){
	seat[r][c]=a[k];
	k++;
	if(seat[r][c]==xiao_r){
		cout<<c<<" "<<r;
	}
	
	for(int i=1;i<=4;i++){
		int tr=r+fr[i];
		int tc=c+fc[i];
		
		if(tr>=1&&tr<=n&&tc>=1&&tc<=m&&seat[tr][tc]==0){
			dfs(tr,tc);
		}	
	}
} 

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			xiao_r=a[i];
		}
	}
	sort(a+1,a+m*n+1,cmp);
	dfs(1,1);
	return 0;
}