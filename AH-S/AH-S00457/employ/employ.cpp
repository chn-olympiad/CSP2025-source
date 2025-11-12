#include<bits/stdc++.h>
using namespace std;
int n,m;
int v[505];
int a[505];
int b[505];
int sum=0;
void dfs(int in,int num){
    if(in==n){
        if(n-num>=m){
            sum=(sum+1)%998244353;
        }
        return ;
    }
    for(int i=1;i<=n;i++){
        if(v[i]==0){
            if(a[in+1]==0 || b[i]<=num){
                v[i]=1;
                dfs(in+1,num+1);
                v[i]=0;
            }else{
                v[i]=1;
                dfs(in+1,num);
                v[i]=0;
            }
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        a[i]=c-'0';
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    dfs(0,0);
    cout<<sum;
    return 0;
}
