#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int f[100005];
int unt=0;
void dfs(int k,int s,int maxn){
    if(k>=3){
         if(s>maxn*2){
             unt++;
             unt=unt%998244353;
             dfs(k,s,maxn);
         }
         if(k>n){
             return ;
         }
    }
    for(int i=1;i<=n;i++){
        if(f[i]==0){
            f[i]=1;
            dfs(k+1,s+a[i],maxn=max(maxn,a[i]));
            f[i]=0;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<unt%998244353;
}
