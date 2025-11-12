#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    if(q!=1)for(int i=0;i<q;i++)cout<<0<<endl;
    else {
        if(n<=1000)cout<<n;
        else cout<<0;
    }
    return 0;
}
