#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt=0,yhh=0;
    for(int i=1;i<=n;i++){
        if(a[i]==k){
            cnt++;
            yhh=0;
        }
        else if(a[i]==0){
            continue;
        }
        else{
            yhh=yhh^a[i];
            if(yhh==k){
                cnt++;
                yhh=0;
            }
        }
    }
    cout<<cnt;
    return 0;
}
