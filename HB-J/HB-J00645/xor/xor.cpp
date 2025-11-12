#include<bits/stdc++.h>
using namespace std;
int a[500005],flag=0,t=2,ans=0,ff=0,sa=0,sb=0,k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1)  sa++;
        if(a[i]==0)  sb++;
        if(a[i]!=1)  flag=1;
        if(a[i]!=1&&a[i]!=0)  ff=1;
    }
    if(flag==0){
        ans+=n/2;
    }
    if(ff==0){
        if(k==1){
            cout<<sa;
            return 0;
        }
        else{
            ans+=sb;
            for(int i=1;i<=n;i++){
                if(a[i]==1&&a[i+1]==1){
                    i++;
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
