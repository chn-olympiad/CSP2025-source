#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt+=(a[i]==0);
    }
    if(!cnt){
        if(k==0) cout<<n/2;
        else cout<<n;
    }
    else{
        if(k==0){
            int x=cnt;
            int p=0;
            for(int i=1;i<=n;i++){
                if(a[i]==1) p++;
                else x+=p/2,p=0;
            }
            if(p) x+=p/2;
            cout<<x;
        }else{
            cout<<n-cnt;
        }
    }
    return 0;
}
