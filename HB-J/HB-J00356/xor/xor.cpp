#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],x,countn;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        int ans=a[i];
        if (ans==k){
            countn++;
            continue;
        }
        for (int j=i+1;j<=n;j++){
            ans^=a[j];
            if (ans==k){
                i=j;
                countn++;
                break;
            }
        }
    }
    cout<<countn;
    return 0;
}
