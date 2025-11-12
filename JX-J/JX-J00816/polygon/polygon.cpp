#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans,sum,maxn;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans+=a[i];
        maxn=max(maxn,a[i]);
    }
    if(n==3){
        if(ans>maxn*2){
            cout<<1;
        }else cout<<0;
    }else{
        int x;
        for(int i=1;i<=n;i++){
            x=i*(n-i+1);
            sum+=x;
        }
        cout<<sum;
    }
    return 0;
}
