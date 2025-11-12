#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5+10;
int a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    //cout<<"t";
    int n,k;
    cin>>n>>k;
    bool fa=1;
    bool fb=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) fa=0;
        if(a[i]>1) fb=0;
    }
    //A
    if(fa){
        cout<<n/2;
        return 0;
    }
    //B
    if(fb){
        int ans=0;
        if(k==0){
            for(int i=1;i<=n;i++){
                if(a[i]==0) ans++;
                else if(a[i]==a[i+1] && i+1<=n ) ans++;
            }
            cout<<ans;
            return 0;
        }
        for(int i=1;i<=n;i++)
            if(a[i]==1) ans++;
        cout<<ans;
        return 0;
    }
    return 0;
}
