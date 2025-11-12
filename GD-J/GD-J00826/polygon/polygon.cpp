#include<bits/stdc++.h>
using namespace std;
const int N=5100;
int n,a[N],df,ans;
void dfs(int i,int ma,int h){
	if(i==n+1){
		if(ma*2<h)
		ans++;
		return;
	}
	dfs(i+1,a[i],h+a[i]);
	dfs(i+1,ma,h);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)
			df=1;
	}
	if(df==0){
		for(int i=1;i<=n-2;i++){
			ans+=i*(n-i-1); 
		}
	}else{
		sort(a+1,a+n+1);
		dfs(0,0,0);
	}
	cout<<ans/2%998244353;
}
