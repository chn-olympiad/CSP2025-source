#include<bits/stdc++.h>
using namespace std;
int n,s[5005],ans,e[5005],f;
int maxx(){
	int num=0;
	for(int i=1;i<=n;i++){
		if(e[i]) num=max(num,s[i]);
	}return num;
}int numm(){
	int num=0;
	for(int i=1;i<=n;i++){
		if(e[i]) num+=s[i];
	}return num;
}void dfs(int flag,int y){
	if(flag>=3 && numm()>2*maxx()){
		ans=(ans+1)%998244353;
	}
	for(int i=y;i<=n;i++){
		if(!e[i]){
			e[i]=1;
			dfs(flag+1,i+1);
			e[i]=0;
		}
	}
}
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i];
	sort(s+1,s+1+n);
	dfs(0,0);
	cout<<ans/2;
	return 0;
}
