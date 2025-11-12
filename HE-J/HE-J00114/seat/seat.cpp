#include<bits/stdc++.h>
using namespace std;
int a[102],a1,n,m,r;
bool g(int x,int y){
	return x>y;
}
int lie(int x,int y){
	if(x%y==0) return x/y;
	return x/y+1;
}
int hang(int x,int y,int z){
	if(z%2==0) return y-x%y+1;
	else if(x%y==0) return y;
	else return x%y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+(n*m+1),g);
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1) r=i;
	}
	int c=lie(r,n);
	cout<<c<<' '<<hang(r,n,c);
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
