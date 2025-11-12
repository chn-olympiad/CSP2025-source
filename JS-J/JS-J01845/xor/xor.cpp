#include<bits/stdc++.h>
using namespace std;
int n,k,a[500086],ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=1,r=n;
    int ending=0;
    for(int r=1;r<=n;r++){
        if(ending>=r){
            r=ending+1;
            continue;
        }
        int cnt=a[r];
        for(int l=r+1;l<=n;l++){
            if(cnt==k){
                ans++;
                ending=l-1;
                break;

            }
            cnt=cnt^a[l];
        }
    }
    cout<<ans;
return 0;
}
