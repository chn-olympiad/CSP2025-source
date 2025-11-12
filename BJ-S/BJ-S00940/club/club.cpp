#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100005][4],b[100005],flag=1,ans;
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
    }
    if(flag=1){
        for(int i=1;i<=n;i++){
            b[i]=a[i][1];
        }
        sort(b+1,b+n+1);
        for(int i=n/2;i<=n;i++) ans+=b[i];
        cout<<ans;
        return 0;
    }
    return 0;
}
