#include<bits/stdc++.h>
using namespace std;
int a[5001],b,c,ans;
void dfs(int x,int y,int z){
	if(y>=3){
		if(a[x]*2<z){
			ans++;
		}
	}
	for(int i=x+1;i<=b;i++){
		dfs(i,y+1,z+a[i]);
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>b;
	for(int i=1;i<=b;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+b);
	dfs(0,0,0);
	cout<<ans;




	return 0;
}
