#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[1145145],ans=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        int oo=a[i];
        if(oo==k){
            ans++;
            cout<<i<<' '<<i<<endl;
        }
        for(int j=i-1;j>=0;j--){
            oo=oo^a[j];
            if(oo==k){
                ans++;
                cout<<j<<' '<<i<<endl;
            }
        }
    }cout<<ans;
    return 0;
}

