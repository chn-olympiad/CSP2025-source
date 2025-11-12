#include<bits/stdc++.h>
using namespace std;
int n;
int cnt;
int a[5010];  
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    n-=2;
    for(int i=1;i<=n;i++){
        cnt+=i;
        cnt%=998244353;
    }
    cout<<cnt;
    return 0;
}
