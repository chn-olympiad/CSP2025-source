#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,i,j,l=1,c=0,ans=0;
    cin>>n>>k;
    int a[n+1];
    bool b[2000000]={};
    for(i=1;i<=n;i+=1){
        cin>>a[i];
    }
    for(i=1;i<=n;i+=1){
        b[0]=1;
        c^=a[i];
        if(b[c^k]){
            c=0;
            ans+=1;
            for(j=l;j<=i;j+=1){
                c^=a[j];
                b[c]=0;
            }
            l=i+1;
            c=0;
        }
        else{
            b[c]=1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
