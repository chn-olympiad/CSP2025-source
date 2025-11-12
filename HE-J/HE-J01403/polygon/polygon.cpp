#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n;
int a[N];
int ans;
void dfs(int x,int sum,int maxx,int d,int nex){
	if(x>d){
		if(sum>2*maxx){	
			ans++;
		}
		return ;
	}
	for(int i=nex+1;i<=n;i++){
		dfs(x+1,sum+a[i],a[i],d,i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int d=3;d<=n;d++){
		dfs(1,0,0,d,0);
	}
	cout<<ans;
	return 0;
}
