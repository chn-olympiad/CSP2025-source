#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[505];
string s;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    int num=1;
    for(int i=1; i<=n; i++)
        cin>>a[i],num+=(a[i]==0);
    if(1){
        int ans=1;
        for(int i=1; i<=n-num; i++){
            ans*=i;
            ans%=998,244,353;
        }
        cout<<ans;
    }
    return 0;
}
