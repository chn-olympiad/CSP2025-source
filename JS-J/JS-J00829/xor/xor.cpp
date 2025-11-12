#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
int n,k,a[N],f[N],ans=0,l=1,r=1;
int sqh(int x,int y){
    if(x==y)return a[x];
    else return f[y]^f[x-1];
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        f[i]=a[i]^f[i-1];
    }
    while(l<=n&&r<=n&&r<=l){
        int cnt=sqh(r,l);
        if(cnt==k){
            ans++;
            r=l+1;
            l=r;
        }
        else{
            l++;
            if(l==n+1){
                r++;
                l=r;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
