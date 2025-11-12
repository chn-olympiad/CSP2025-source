#include<bits/stdc++.h>
using namespace std;
int a[500005];
int n,k,sum,tot,l,h,y;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            sum++;
        }
        else if(a[i]==0){
            tot++;
        }
    }
    if(sum==n){
        if(k==1){
            cout<<n;
            return 0;
        }
        if(k==0){
            cout<<n/2;
            return 0;
        }
        else {
            cout<<0;
            return 0;
        }
    }
    else if((sum+tot)==n){
        if(k==1){
            cout<<sum;
            return 0;
        }
        if(k==0){
            for(int i=1;i<=n;i++){
                if(a[i]==1&&a[i+1]==1){
                    h++;
                    i++;
                }
            }
            cout<<h+tot;
            return 0;
        }
        else{
            cout<<0;
            return 0;
        }
    }
    else{
        for(int i=1;i<=n;i++){
            if(a[i]==k){
                y++;
            }
        }
        cout<<y;
    }
    return 0;
}
