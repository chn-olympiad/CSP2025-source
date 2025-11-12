#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
long long ans;
bool c[5010];
void f(int m,int sum,int x,int maxn,int y){
    if(x==m){
        if(sum>2*maxn){
            ans++;
            ans%=998244353;
        }
        return ;
    }
    for(int i=y;i<=n;i++){
        if(!c[i]){
            c[i]=1;
            if(a[i]>maxn) f(m,sum+a[i],x+1,a[i],i);
            else f(m,sum+a[i],x+1,maxn,i);
            c[i]=0;
        }
    }
    return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=3;i<=n;i++){
        f(i,0,0,0,1);
    }
    printf("%d",ans);
    return 0;
}
