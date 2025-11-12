#include<bits/stdc++.h>
using namespace std;
int a[1000],n,maxn=0,sum=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<=2) cout<<0;
    else{
        for(int i=1;i<=n;i++){
            cin>>a[i];
            maxn=max(maxn,a[i]);
            sum+=a[i];
        }
        if(sum>maxn*2) cout<<1;
        else cout<<0;
    }

    return 0;
}
