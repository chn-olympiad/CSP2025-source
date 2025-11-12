#include<bits/stdc++.h>
using namespace std;

int a[1000005],n,k,l=1,r=1,cnt;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;l<=n,r<=n;i++){
        int t=0;
        for(int j=l;j<=r;j++){
            t^=a[j];
        }
        if(t==k){
            l=l+r-l+1;
            r=l;
            cnt++;
        }else{
            if(r==n){
                l++;
                r=l;
            }else{
                r++;
            }

        }

    }
    cout<<cnt;
    return 0;
}

