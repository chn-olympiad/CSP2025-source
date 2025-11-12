#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005]={},ans=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k==0){
        a[n+1]=2;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                int sl=1;
                while(a[i+1]==0){
                    i++;
                    sl++;
                }
                ans+=sl;
            }
            if(a[i]==1){
                int sl=1;
                while(a[i+1]==1){
                    i++;
                    sl++;
                }
                ans+=sl/2;
            }
        }
        cout<<ans;
        return 0;
    }
    if(k==1){
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                int sl=1;
                while(a[i+1]==1){
                    i++;
                    sl++;
                }
                ans+=sl;
            }
        }
        cout<<ans;
        return 0;
    }
    return 0;
}