#include<bits/stdc++.h>
using namespace std;
const int modd=998244353;
int n,ans;
int l[5010];
void dfs(int r,int sum){
	for(int k=r;k<=n;k++){
		if(l[k]<sum){
		    ans++;
		    ans=ans%modd;
		}  
		dfs(k+1,sum+l[k]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)  cin>>l[i];
    for(int i=1;i<=n-2;i++){
    	for(int j=i+1;j<=n-1;j++){
    		dfs(j+1,l[i]+l[j]);
		}
	}
	ans=ans%modd;
	cout<<ans<<endl;
	return 0;
}

 
