#include<bits/stdc++.h>
using namespace std;
const int N=100000,M=998244353;
int n,m[N],y,h,ma,b;
void dfs(int x){
	if(x<3){
		return;
	}
	for(int i=0;i<=n-x;i++){
		for(int j=i;j<x+i;j++){
			h+=m[j];
			ma=max(ma,m[j]);		
		}
	}
	if(h>ma*2){
		y++;
	}
	dfs(x-1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m[i];
	}
	if(n==3){
		dfs(n);
	}
	if(n==4){
		for(int i=0;i<4;i++){
			h+=m[i];
			ma=max(ma,m[i]);
		}
		if(h>ma*2){
			y++;
		}
		h=m[0]+m[1]+m[2];
		ma=max(m[0],m[1]);
		ma=max(ma,m[2]);
		if(h>ma*2){
			y++;
		}	
		h=m[0]+m[1]+m[3];
		ma=max(m[0],m[1]);
		ma=max(ma,m[3]);
		if(h>ma*2){
			y++;
		}	
		h=m[0]+m[3]+m[2];
		ma=max(m[0],m[2]);
		ma=max(ma,m[3]);
		if(h>ma*2){
			y++;
		}	
		h=m[3]+m[1]+m[2];
		ma=max(m[3],m[1]);
		ma=max(ma,m[2]);
		if(h>ma*2){
			y++;
		}			
	}
	cout<<y;
}
