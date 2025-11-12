#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c[505],p[505];
char s[505];
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++)p[i]=i;
    int ans=0;
    do{
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='0'||cnt>=c[p[i]])cnt++;
        }
        ans+=(cnt<=n-m);
    }while(next_permutation(p+1,p+n+1));
    cout<<ans;
    return 0;
}
