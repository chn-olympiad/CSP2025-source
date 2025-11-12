#include<bits/stdc++.h>
using namespace std;
int n,k,a[500022],y[10000022][2],yi,xmax,zmax;
int yhh(int x,int y){
	int s=a[x];
	for(int i=x+1;i<=y;i++){
		s=s^a[i];
	}return s;
}
bool bk(int x,int y,int q,int p){
	for(int i=x;i<=y;i++){
		if(i>=q and i<=p) return true;
	}return false;
} 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(yhh(i,j)==k) y[yi][0]=i,y[yi][1]=j,yi++;
		}
	}cout<<yi;
	return 0;
}
