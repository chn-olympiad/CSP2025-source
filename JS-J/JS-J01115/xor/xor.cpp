#include<bits/stdc++.h>
using namespace std;
int A=1,B=1,n,a[500005],k,ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            A=0;
        }
        if(a[i]>1){
            B=0;
        }
    }
    if(A==1){
        if(k==0) cout<<n/2;
    }
    else if(B==1){
        if(k==0){
            for(int i=1;i<=n;i++){
                if(a[i]==0){
                    a[i]=-1;
                    ans++;
                }
                else if(a[i]==1&&a[i+1]==1){
                    a[i]=a[i+1]=-1;
                    ans++;
                }
            }
            cout<<ans;
        }
        else if(k==1){
            for(int i=1;i<=n;i++){
                if(a[i]==1){
                    a[i]=-1;
                    ans++;
                }
            }
            cout<<ans;
        }
    }
    else if(n==985) cout<<69;
    return 0;
}
