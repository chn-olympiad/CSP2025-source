#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],b[500005],c[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        for(int j=1;j<=i;j++){
            c[j]^=a[i];
            if(c[j]==k){
                b[i]=max(b[i],b[j-1]+1);
            }
            else{
                b[i]=max(b[i],b[i-1]);
            }
        }
    }
    printf("%d",b[n]);
    return 0;
}
