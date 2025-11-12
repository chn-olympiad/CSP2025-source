#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,x,s=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>x;
        a[i]=x^a[i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((a[i-1]^a[j])==k){
                s++;
                i=j;
            }
        }
    }
    cout<<s;
    return 0;
}
