#include<bits/stdc++.h>
using namespace std;
int n,b,a,k,mx;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a;
        b=b^a;
        if(b>k) b=0;
        else if(b==k){
            mx++;
            b=0;
        }
    }cout<<mx;
    return 0;
}

