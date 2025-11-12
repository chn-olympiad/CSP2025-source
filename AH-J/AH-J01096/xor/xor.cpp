#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],s;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;++i){
        int t=a[i];
        if(t==k){
            s++;
            continue;
        }
        for(int j=i+1;j<=n;j++){
            if((t^a[j])==k){
                i=j;
                s++;
                break;
            }
            else t=t^a[j];
        }
    }
    cout<<s;
    return 0;
}
