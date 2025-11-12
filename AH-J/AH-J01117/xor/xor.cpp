#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500005];
int f[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        int l=-1;
        for(int j=i,x=0;j>=1;j--){
            x=x^a[j];
//            if(i==4){
//                cout<<endl<<x<<endl;
//            }
            if(x==k){
                l=j;
                break;
            }
        }
        if(l==-1)continue;
        for(int j=l-1;j>=1;j--){
            f[i]=max(f[i],f[j]);
        }
        f[i]++;
//        cout<<i<<" "<<l<<" "<<f[i]<<endl;
    }
    for(int i=1;i<=n;i++)ans=max(ans,f[i]);
    printf("%d",ans);
    return 0;
}
