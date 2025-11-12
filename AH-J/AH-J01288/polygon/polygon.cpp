#include<bits/stdc++.h>
using namespace std;
int n,a[5005],s;
void dfs(int h,int ma,int hou,int b){
	if(hou>n)return;
	if((b>2)&&(h>(ma*2)))s++;
	for(int i=hou+1;i<=n;i++){
		dfs(h+a[i],max(ma,a[i]),i,b+1);
	}
	dfs(a[hou+1],a[hou+1],hou+1,1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(a[1],a[1],1,1);
	cout<<s-1;
	return 0;
}
