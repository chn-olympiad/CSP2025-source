#include<bits/stdc++.h>
using namespace std;
int a[500001];
int n,m;
int ans=0;
unsigned maxxy(unsigned x,unsigned y){
	return x>y?x:y;
}
int i;
unsigned xornum=0;
unsigned xorab(unsigned a,unsigned b){
	
}
int getans(int x){
	int ansnow;
	for(i=x;i<=n;++i){
		xornum=xorab(xornum,a[i]);
		if(xornum==m){
			ansnow=1+getans(i+1);
			break;
		}
	}
	return maxxy(ansnow,getans(x+1));
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	getans(1);
	return 0;
}
