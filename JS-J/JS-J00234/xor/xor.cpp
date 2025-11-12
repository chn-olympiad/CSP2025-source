#include<bits/stdc++.h>
using namespace std;

int n,k,a[500010],c[500010],last[2000010];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    memset(last,255,sizeof(last));
    last[0]=0;
    scanf("%d%d",&n,&k);
    int cnt=0,ans=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        c[i]=c[i-1]^a[i];
        int x=k^c[i];
        if(last[x]!=-1&&cnt<last[x]+1){
            cnt=i;
            ans++;
        }
        last[c[i]]=i;
    }
    printf("%d\n",ans);
    return 0;
}
