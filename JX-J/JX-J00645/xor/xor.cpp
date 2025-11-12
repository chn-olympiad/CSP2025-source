#include <bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500010],p,y,m;
long long x;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    m=1;
    for(int i=1;i<=n;i++){
        bool f=false;
        for(int j=i;j>=m;j--){
            if(j==i&&a[j]==k){
                f=true;
                ans++;
                break;
            }
            x=0;
            for(int h=i;h>=j;h--){
                x^=a[h];
            }
            if(x==k){
                f=true;
                ans++;
                break;
            }
        }
        if(f){
            m=i+1;
        }
    }
    printf("%d",ans);
    return 0;
}
