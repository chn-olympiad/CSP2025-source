#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,sum=0,maxn=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        maxn=max(maxn,a[i]);
    }
    if(sum>maxn*2&&n>=3){
        cout<<1;
        return 0;
    }
    cout<<0;

    return 0;
}
