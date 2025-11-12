#include<bits/stdc++.h>
using namespace std;
int a[5010];
long long ans = 0;
const int N=1e5;
int p;
int pa[6000][6000]={0};
void dfs(int v,long long maxn,int n,long long  sum){
if(n<=0||v>=p){
if(sum >maxn*2&&pa[n][v])ans=(ans+1)%998244353;pa[n][v]=1;
return ;}

if(a[v]>maxn){dfs(v+1,a[v],n-1,sum+a[v]);dfs(v+1,maxn,n-1,sum);}


else {dfs(v+1,maxn,n-1,sum+a[v]);dfs(v+1,maxn,n-1,sum);}
}
int main(){

//freopen("polygon.in","r",stdin);
//freopen("polygon.out","w",stdout);

int n;

cin>>p;
for(int i = 1 ; i<= p ; i++)cin>>a[i];

for(int i = 1 ; i<= p ;i++)dfs(1,-1,i,0);

cout<<ans<<endl;
return 0;
}
