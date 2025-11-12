#include<bits/stdc++.h>
using namespace std;
int a[500010];
int sum[500010];
int vis[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,c;
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<c;
    return 0;
}
