//10pts
#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int n,k;
int a[MAXN];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    bool flag1=true;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) flag1=false;
    }
    if(flag1&&k==0){    //1,3 10pts
        cout<<n/2;
        return 0;
    }
    return 0;
}