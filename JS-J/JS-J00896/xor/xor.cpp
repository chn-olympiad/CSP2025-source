#include<bits/stdc++.h>
using namespace std;
const int M=(1<<20)+10,N=5e5+5;
int bu[N],cnt[M],a[N],f[N];
int n,k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    memset(cnt,-1,sizeof(cnt));
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    bu[0]=0;
    f[0]=0;
    cnt[0]=0;
    for(int i=1;i<=n;i++){
        int nefind=a[i]^k;
        int findans=nefind^bu[i-1];
        if(cnt[findans]==-1){
            f[i]=f[i-1];
        }
        else{
            f[i]=max(f[cnt[findans]]+1,f[i-1]);
        }
        bu[i]=bu[i-1]^a[i];
        cnt[bu[i]]=i;
    }
    printf("%d\n",f[n]);
    return 0;
}
