#include<bits/stdc++.h>
using namespace std;
int p,q;
int m;
int ls[500034],xr[500034][20];
int xor1(int l,int r){
	return xr[i][j];
}
void dfs(int a,g){
	if(a >= p){
		if(a == p){
			m = max(m,g);
		}
		return;
	}
	for(int i = a;i <= p;i++){
		for(int j = i;j <= p;j++){
			if(xor1(i,j) == 1){
				for(int k = j;k <= p;k++){
					dfs(k,g+1);
				}
			}
		}
	}
}
int main(){
	freopen("xor1.in","r",stdin);
	//freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>p>>q;
	
	for(int i = 1;i <= p;i++){
		cin>>ls[i];
	}
	for(int i = 1;i <= p;i++){
		xr[i][0] = ls[i];
	}
	for(int j=1;(1<<j)<=p;j++){
		for(int i=1;i+(1<<j) <= p;i++){
			xr[i][j] = (xr[i][j-1] ^ xr[i+(1<<(j-1))][j-1]);
		}
	}
	return 0;
} 
