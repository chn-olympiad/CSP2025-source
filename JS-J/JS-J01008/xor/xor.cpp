#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,k,a[MAXN],ans,cnt=0;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(!k){
        for(int i=0;i<n;i++){
            if(!a[i]){
                cnt++;
            }
        }
        cout<<cnt;
        return 0;
    }
    ans=a[0];
    for(int i=0;i<n;i++){
        if(ans==k){
            cnt++;
            ans=a[i+1];
        }
        if(ans==a[i]){
            continue;
        }
        if(ans!=k){
            ans^=a[i];
        }
    }
    cout<<cnt;
    return 0;
}
