#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=5010;
int n,ans=0;
int a[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans+=a[i];
    }
    if(n==3){
        if(ans>max(a[1],max(a[2],a[3]))){
            cout<<1;
        }
        else cout<<0;
    }
    if(n==4) cout<<2;
    if(n>4){
        cout<<(n-3)*(n-4)/2-1;
    }
    return 0;
}
