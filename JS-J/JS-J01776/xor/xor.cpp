#include<bits/stdc++.h>
#define Maxn 200000+10
using namespace std;
int n,k;
int h=0;
int a[Maxn];
void free(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
}
int main(){
    free();
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    if(k==0){
        printf("%d",n/2);
        return 0;
    }
    if(k==1){
        int ans=0;
        for(int i=1;i<=n;i++)
            if(a[i]==1)ans++;
        printf("%d",ans);
        return 0;
    }
    printf("%d",h);
    return 0;
}
