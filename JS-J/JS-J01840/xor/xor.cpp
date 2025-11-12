#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=1<<22;
int n,m,a[N],f[N],s[M],ans,lst=-1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),f[i]=f[i-1]^a[i];
    for(int i=1;i<M;i++)
        s[i]=-1;
    for(int i=1;i<=n;i++){
        int x=m^f[i];
        if(s[x]!=-1&&s[x]>=lst)
            ++ans,s[x]=-1,lst=i;
        s[f[i]]=i;
    }
    printf("%d\n",ans);
    return 0;
}
