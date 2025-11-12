#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m,a[505],v[505],ans;
string s;
void dfs(int x,int l,int ml){
	if(x==n){
		if(l>=m) ans=(ans+1)%mod;
		return;
	}
	 for(int i=1;i<=n;i++){
	 	 if(v[i]==0){
	 	 	if(ml>=a[i]){
	 	 		v[i]=1;
	 	 		dfs(x+1,l,ml+1);
	 	 		v[i]=0;
			  }else{
			  	if(s[x]=='0'){
	 	 		v[i]=1;
	 	 		dfs(x+1,l,ml+1);
	 	 		v[i]=0;
			  }else{
			  	v[i]=1;
			  	dfs(x+1,l+1,ml);
			  	v[i]=0;
			  }
			  }
	 	 	
		  }
	 }
	 return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m;  
    cin>>s;
    for(int i=1;i<=n;i++){
    	cin>>a[i]; 
	}
    dfs(0,0,0);
    cout<<ans;


	return 0;
}

