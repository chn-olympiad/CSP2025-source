#include <bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500005];
int s[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=a[i]^s[i-1];
    }
    int x=n;
    for(int i=n;i>=1;i--){
        for(int j=i;j<=x;j++){
            if(int(s[j]^s[i-1])==k){
                ans++;
                x=i-1;
                break;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
