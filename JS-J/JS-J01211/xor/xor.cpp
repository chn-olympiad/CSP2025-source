#include<bits/stdc++.h>
using namespace std;
int a[500003];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,cnt=0;cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int x=a[i];
        for(int j=i+1;j<n;j++){
            x=(x xor a[j]);
            if(x==k){
                cnt++;
                i=j+1;
                break;
            }
        }
    }
    cout<<cnt;
    return 0;
}
