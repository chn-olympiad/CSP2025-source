#include<bits/stdc++.h>
using namespace std;

int n,k,p[105],ans,cur=1;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    if(k==1){
        for(int i=2;i<=n;i++){
            if(p[i]==p[i-1])
                cur++;
            else{
                cur=1;
                ans++;
                i++;
            }
            if(cur==3){
                cur=1;
                ans++;
                i++;
            }
        }
    }
    if(k==0){
        for(int i=2;i<=n;i++){
            if(p[i]!=p[i-1])
                cur++;
            else{
                cur=1;
                ans++;
                i++;
            }
            if(cur==3){
                cur=1;
                ans++;
                i++;
            }
        }
    }

    cout<<ans;

    return 0;
}
