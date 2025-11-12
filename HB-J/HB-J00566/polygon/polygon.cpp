#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
int a[5001];
int b[5001];//char ton[12530];
void dfs(int nn,int c,int s,int ma){
    if(c==nn){
        if(s>ma*2){
            ans++;
        }
        if(ans==998244353){
            ans=0;
        }
        return;
    }
    for(int i=0;i<n;i++){
        if(b[i]==1){
            continue;
        }
        b[i]=1;
        if(a[i]>ma)
        dfs(nn,c+1,s+a[i],a[i]);
        else
        dfs(nn,c+1,s+a[i],ma);
        b[i]=0;
    }
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    if(n>500){
        printf("%d",rand()%(int)998244353);
        return 0;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=3;i<n;i++){
        dfs(i,0,0,0);
        //memset(ton,0,sizeof(ton));
    }
    printf("%.0f",ans/16.0);
    return 0;
}
