#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0,i,j;
int a[1000000];
int main(){
    freopen("xor.in","r",stdin);
    cin>>n>>k;
    for(int x=1;x<=n;x++)
        cin>>a[x];
    for(i=1;i<=n;i++){
        if(a[i]==k)
            ans+=1;
    }
    for(i=n;a>=0;i--)
        if(a[i-1]==k)
            break;
    for(;i<=n;i++){
        for(j=i+1;j<=n;j++){
            a[j]=a[j-1]^a[j];
            cout<<a[j]<<" ";
            if(a[j]=k){
                ans+=1;
                i=j;
                break;
            }
        }
    }
    cout<<ans;
    freopen("xor.out","w",stdout);
    return 0;
}
