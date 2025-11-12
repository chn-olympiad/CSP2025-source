#include<bits/stdc++.h>
using namespace std;

int n,k,a[500005];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    if(k==0){
        int cnt=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            cnt+=a[i];
        }
        printf("%d\n",cnt/2);
    }else{
        int cnt=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            cnt+=a[i];
        }
        printf("%d\n",cnt);
    }
    return 0;
}
