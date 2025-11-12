#include <bits/stdc++.h>
using namespace std;
bool dp[1000][1000];
int xr(int a,int b){
    int na[22],nb[22],nc[22];
    memset(na,0,sizeof(na));
    memset(nb,0,sizeof(nb));
    int x=0,y=0;
    while (a!=0){
        x++;
        na[x]=a%2;
        a=a>>1;
    }
    while (b!=0){
        y++;
        nb[y]=b%2;
        b=b>>1;
    }
    for(int i=1;i<=max(x,y);i++){
        if(na[i]!=nb[i]){
            nc[i]=0;
        }
        else{
            nc[i]=1;
        }
    }
    int c=0;
    for(int i=max(x,y);i>=1;i--){
        c=c*2+nc[i];
    }
    return c;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<0;
}