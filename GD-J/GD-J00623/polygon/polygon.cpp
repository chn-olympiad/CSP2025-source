#include<bits/stdc++.h>
using namespace std;
int n,pre,p,a[5010],ans;
void dfs(int dep,long long sum,long long max,int c){
	if(dep>n){
		if(c>=3&&sum>(max<<1)) ans=(ans+1)%998244353;
		return ;
	}
	dfs(dep+1,sum,max,c);//不选第dep个
	dfs(dep+1,sum+a[dep],(a[dep]<max?max:a[dep]),c+1);//选第dep个 
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    bool f=1;
    for(int i=1;i<=n;++i) cin>>a[i],f=(a[i]==1);
    if(f){
	    for(int i=1;i<=n;++i){
	    	p+=i;
	    	pre=(pre+p)%998244353;
		}
		cout<<pre;
	}
	else{
		dfs(1,0,0,0);
		cout<<ans;
	}
    return 0;
}
