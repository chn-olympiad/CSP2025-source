#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int l=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            l++;
        }
    }
    if(k==0){
        int ans=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                ans++;
            }else if(a[i+1]==1){
                ans++;
                i++;
            }else{
                continue;
            }
        }
        cout<<ans;
        return 0;
    }else{
        cout<<l;
    }
    return 0;
}
