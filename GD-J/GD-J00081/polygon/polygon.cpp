#include<bits/stdc++.h>
using namespace std;
long long n,a[10005],num; 
void dfs(int k,int h,int x){
	if(k>=3){
		if(h>a[x]*2){
			num++;
		}
	}
	if(k>n){
		return;
	}
	for(int i=x+1;i<=n;i++){
		dfs(k+1,h+a[i],i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(0,0,0);
	cout<<num;
	return 0;
}
