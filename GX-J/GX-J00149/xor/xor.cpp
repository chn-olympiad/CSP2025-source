#include <bits/stdc++.h>
using namespace std;
long long n,k,a[100005]={0};
bool A=true,C=true;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            A=false;
            if(a[i]!=0){
                C=false;
            }
        }
    }
    if(A) cout<<n;
    return 0;
}
