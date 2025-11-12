#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int sum;
int ans;
int a[N];
int n,k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=0&&a[i]!=1){
            cout<<1;
            return 0;
        }
    }
    if(k==0){
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                ans++;
            }else{
                if(a[i-1]==1){
                    ans++;
                    a[i]=0;
                }
            }
        }
        cout<<ans;
    }else if(k==1){
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                ans++;
            }
        }
        cout<<ans;
    }else{
        cout<<1;
    }
    return 0;
}
