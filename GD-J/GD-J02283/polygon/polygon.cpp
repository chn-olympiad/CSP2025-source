#include<bits/stdc++.h>
using namespace std;
int m,a[5005],b[5005],zh=0;
bool ch(int x){
	int c=0,d=0;
	for(int i=1;i<=x;i++){
		if(a[b[i]]>=c) c=a[b[i]];
		d+=a[b[i]];
	}
	if(d>c*2) return 1;
	else return 0;
}
void dfs(int s,int x,int y){
	if(y==s+1){
		if(ch(s)){
			zh++;
		}
		return ;
	}
	for(int i=x;i<=m;i++){
		b[y]=i;
		dfs(s,i+1,y+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=3;i<=m;i++){
		dfs(i,1,1);
	}
	cout<<zh%998%244%354;
	return 0;
}
