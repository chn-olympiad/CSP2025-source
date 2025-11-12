#include<iostream>
#include<cstring>
using namespace std;
int n,k,a[500005],las[4000005],f[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    memset(las,-1,sizeof(las));
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) a[i]=a[i-1]^a[i];
    for(int i=n;i>=0;i--) a[i+1]=a[i];
    n++;
    for(int i=1;i<=n;i++){
        if(las[a[i]^k]==-1) f[i]=f[i-1];
        else{
            int pos=las[a[i]^k];
            f[i]=max(f[i-1],f[pos]+1);
        }
        las[a[i]]=i;
    }
    //for(int i=1;i<=n;i++) cout<<f[i]<<" ";
    cout<<f[n];
}
// f[i]=max(f[i-1],) i can =0!