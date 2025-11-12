#include <bits/stdc++.h>
using namespace std;
int n,a[5001],aannss,m,z,x,u;
void DFS(int M,int Z,int X,int U){
	if(U==n){
		if( !(M*2>=Z) && X>=3 ) aannss=(aannss++)%998244353;	
		m=a[U],z=Z+a[U],x=X+1;
		if( !(m*2>=z) && x>=3 ) aannss=(aannss++)%998244353;
		return ;
	}
	if(U==n+1){
		if( !(M*2>=Z) && X>=3 ) aannss=(aannss++)%998244353;
		return ;
	}
	DFS(a[U+1],Z+a[U]+a[U+1],X+2,U+2);
	DFS(a[U+1],Z+a[U+1],X+1,U+2);
	DFS(a[U],Z+a[U],X+1,U+2);//Ñ¡Ôñ 
	DFS(M,Z,X,U+2);//²»Ñ¡ 
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	DFS(0,0,0,1);
	cout<<aannss;
	return 0;
}
