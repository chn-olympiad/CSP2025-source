#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=500005;
int a[N],f[N];
int pos,ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        f[i]=f[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        int x=pos;
        bool fl=0;
        while(pos<=i){
            if(((f[i]^f[pos])==k && i!=pos) || (i==pos && a[i]==k)){
                ans++;
                fl=1;
                pos=i;
                break;
            }
            pos++;
        }
        if(fl==0){
            pos=x;
        }
    }
    cout<<ans;
    return 0;
}
