#include<bits/stdc++.h>
using namespace std;
const int N=5000+5;
int n,a[N];
long long dfs(long long sum,int maxa,int num,int id){
	if(id>n){
		if(sum>2*maxa&&num>=3){
			return 1;
		}
		return 0;
	}
	return dfs(sum,maxa,num,id+1)+dfs(sum+a[id],max(a[id],maxa),num+1,id+1);
}
int slove(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<dfs(0,0,0,1);
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	slove();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
