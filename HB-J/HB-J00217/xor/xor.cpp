#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,a[500005],k,ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    m=a[1];
    for(int i=1;i<=n;i++){
        cout<<m<<" ";
        if(a[i]==k || m==k){
            ans++;
            m=a[i+1];
        }
        else m=m^a[i+1];
    }
    cout<<ans;
    return 0;
}
