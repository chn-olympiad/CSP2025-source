#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0,a[10000001],s[10000001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cout<<(a[i]^a[j])<<endl;
            if((a[i]^a[j])==k){
                ans++;
                i=j;
            }
        }
    }
    cout<<ans;
    return 0;
}


