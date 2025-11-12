#include<bits/stdc++.h>
using namespace std;
int n,a[5001],c,an;
void dfs(int j,int k){
	c+=a[j];
	if(k==0){
		if(c>2*a[j]){
			an++;
		}
		return;
	}
	for(int i=j+1;i<=n;i++){
		dfs(i,k-1);
		c-=a[i];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n;j++){
			c=0;
			dfs(j,i-1);
		}
		
	}
	cout<<an;
}
