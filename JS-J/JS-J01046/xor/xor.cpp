#include <bits/stdc++.h>
using namespace std;

int a[500010],n,k,s,p,l=1,ans;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        s^=a[i];
        p=0;
        for(int j=l;j<=i;j++){
            if((s^p)==k){
                ans++;
                s=0;
                l=i+1;
                break;
            }
            p^=a[j];
        }
    }
    cout<<ans<<endl;
    return 0;
}
