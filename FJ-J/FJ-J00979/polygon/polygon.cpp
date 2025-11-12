#include<bits/stdc++.h>
using namespace std;
#define ing long long
int a[10000];
int sum=0;
int n;
bool cmp(int a,int b){
	return a>b;
}
void dfs(int s,int j,int k){
	if(j>n){
		if(s>k)sum++;
		return ;
	}
	for(int i=1;i<=2;i++){
		if(i==1){
			dfs(s+a[j],j+1,k);
		}else{
			dfs(s,j+1,k);
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	
	for(int i=1;i<=n-2;i++){
		dfs(0,i+1,a[i]);
	}
	cout<<sum<<endl;
	return 0;
}
