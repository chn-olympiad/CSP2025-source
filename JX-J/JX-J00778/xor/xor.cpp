#include<bits/stdc++.h>
using namespace std;
int k,n,ans;
int a[200005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k==0){
        int num=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                ans++;
                ans+=num/2;
                num=0;
            }
            else if(a[i]==1){
                num++;
            }
        }
        ans+=num/2;
    }
    else{
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                ans++;
            }
        }
    }
    cout<<ans;
}
