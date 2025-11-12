#include<bits/stdc++.h>
using namespace std;

int n,a[1005],cnt=0;

void dfs(int i,int Max,int And,int k){
	if(i==n-1){
		return ;
	} 
	if(And>2*Max && k>2){
		cnt++;
	}
	for(int j=i+1;j<n;j++){
		dfs(j,a[j],And+a[j],k+1);
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	dfs(-1,0,0,0);
	cout<<cnt<<endl; 
	return 0;
}
