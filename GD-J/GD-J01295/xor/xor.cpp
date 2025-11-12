#include<bits/stdc++.h>
#define N 500005
#define V (1<<21)
using namespace std;
int n,k;
int lst[V];
int f[N];
int x[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",x+i);
        x[i]^=x[i-1];
    }
    memset(lst,-1,sizeof lst);
    lst[0]=0;
    f[0]=0;
    for(int i=1;i<=n;i++){
        f[i]=f[i-1];
        if(lst[x[i]^k]!=-1){
            f[i]=max(f[i],f[lst[x[i]^k]]+1);
        }
        lst[x[i]]=i;
    }
    printf("%d\n",f[n]);
}
