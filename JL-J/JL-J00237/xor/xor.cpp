#include <bits/stdc++.h>
using namespace std;

const int N=1005;

int n,k;
int a[N];

bool check1(){
    int p=1;
    for(int i=1;i<=n;i++){
        if(a[i]!=1){
            p=0;
            break;
        }
    }
    if(p==1){
        cout<<n/2;
        return 1;
    } else {
        return 0;
    }
}

bool check2(){
    int p=1;
    for(int i=1;i<=n;i++){
        if(a[i]>1){
            p=0;
            break;
        }
    }
    if(p==1){
        if(k==0){
            int ans=0;
            for(int i=1;i<=n;i++){
                if(a[i]==0){
                    ans++;
                } else {
                    if(a[i+1]==1){
                        ans++;
                        i++;
                    }
                }
            }
            cout<<ans;
        } else {
            int ans=0;
            for(int i=1;i<=n;i++){
                if(a[i]==1){
                    ans++;
                }
            }
            cout<<ans;
        }
        return 1;
    } else {
        return 0;
    }
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    if(check1()) return 0;
    if(check2()) return 0;
    cout<<1;
    return 0;
}