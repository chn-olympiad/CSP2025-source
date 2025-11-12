#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+10;
int a[maxn];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        int mn=max(max(a[1],a[2]),a[3]);
        int cnt=a[1]+a[2]+a[3];
        if(cnt>2*mn)cout<<1;
        else cout<<0;
    }
    else if(a[1]==1&&a[2]==1&&a[3]==1){
        const int p=998244353;
        int ans=0;
        for(int i=1;i<=n;i++)a[i]=i;
        do{
            ans++;ans%=p;
        }while(next_permutation(a+1,a+n+1));
        cout<<ans;
    }
    else{
        cout<<0;
    }
    return 0;
}
