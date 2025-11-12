#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],a1,p,r,c;
void dfs(int x,int y,int cnt){
	if(cnt==1){
		r=x;
		c=y;
		return;
	}
	if(y%2==0){
		if(x%n==1){
			dfs(x,y+1,cnt-1);
		}else{
			dfs(x-1,y,cnt-1);
		}
	}else{
		if(x%n==0){
			dfs(x,y+1,cnt-1);
		}else{
			dfs(x+1,y,cnt-1);
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	} 
	a1=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		cout<<a[i]<<' ';
	} 
	for(int i=n*m;i>=1;i--){
		if(a1==a[i]){
			p=n*m+1-i;
			break;
		}
	}
	cout<<p<<endl;
	dfs(1,1,p);
	cout<<c<<' '<<r<<endl;
	return 0;
}