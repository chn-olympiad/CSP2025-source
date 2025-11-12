#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.in","w",stdin);
    int n,k,x,ans;
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++){
        scanf("%d",a[i]);
        if (a[i]==k){
            ans++;
            a[i]=-1;
        }
    }
    for (int l=2;l<n;l++){
        for (int m=0;m<n-l+1;m++){
            x=a[m];
            for (int o=1;o<l;o++){
                if (a[o+m]==-1 || x=-1){
                    x=-1,o=l;
                }else{
                    x=x^a[o+m];
                }
                if (x==k){
                    ans++;
                    for (int j=o+m;j<l+o+m){
                        a[j]=-1;
                    }
            }
        }
    }
    printf("%d",ans);
    return 0;
}
