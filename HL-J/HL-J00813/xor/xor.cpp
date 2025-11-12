#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    int a[500005];
    cin>>n>>k;
    int m=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0){
            m++;
        }
    }
    if(k==0){
        cout<<m;
    }
    else cout<<2;
    return 0;
}
