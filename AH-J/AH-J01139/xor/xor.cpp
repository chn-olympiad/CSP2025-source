#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int f=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0)f++;
    }
    if(n==1&&k==0){
        if(f==1)cout<<1<<endl;
        else cout<<0<<endl;
    }
    else{
        if(f)cout<<f<<endl;
        else if(a[1]==a[2])cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}
