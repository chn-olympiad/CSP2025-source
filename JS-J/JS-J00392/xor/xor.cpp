#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int p=0;
    if(k==1){
        for(int i=1;i<=n;i++){
            if(a[i]==1)
                p++;
        }
        cout<<p;
        return 0;
    }
    if(k==0){
        cout<<(n-p)+p/2;
        return 0;
    }
    return 0;
}
