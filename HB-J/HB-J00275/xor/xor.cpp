#include<bits/stdc++.h>
using namespace std;

int a[500001];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,ans=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        if(a[i]==k){
            ans++;
            a[i]=-1;
        }
        else{
            if(a[i-1]==-1)
                continue;
            if(i!=1){
                a[i]=a[i-1]^a[i];
                if(a[i]==k){
                    ans++;
                    a[i]=-1;
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}
