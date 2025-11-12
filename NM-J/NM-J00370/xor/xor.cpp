#include<bits/stdc++.h>

using namespace std;

int n,k,l,r,a[500001],sum_qujian=0,len_qujian,ans=1;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum_qujian^=a[i];
    }
    sum_qujian=0;
    for(int i=1;i<=n;i++){
        for(int x=1;x<=n-i;x++){
            for(int y=x;y<=n;y++){
                k=sum_qujian;
                sum_qujian=0;
                for(int z=x;z<=y;z++){
                    sum_qujian^=a[z];
                }
                if(sum_qujian==k){
                    ans++;
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}
