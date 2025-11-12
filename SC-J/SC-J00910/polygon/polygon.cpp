#include<bits/stdc++.h>
using namespace std;
const int N=5000;
int a[N+10],cnt=0;
int n;
void dfs(int k,int suml,int maxl,int num){
	for(int i=num+1;i<=n-3;i++){
		if(k+1>=3&&suml+a[i]>2*max(maxl,a[i]))cnt++;
		dfs(k+1,suml+a[i],max(maxl,a[i]),i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(0,0,0,0);
	cout<<cnt;
	
	fclose(stdin);fclose(stdout);
	return 0;
}