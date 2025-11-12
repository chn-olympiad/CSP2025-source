#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int maxn=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(maxn<=1){
        int j=3;
        long long ans=0;
        while(j<=n){
            for(int i=j;i<=n;i++)ans=(ans+1)%998244353;
             j++;
        }
        cout<<ans;

        return 0;
    }
    return 0;
}
