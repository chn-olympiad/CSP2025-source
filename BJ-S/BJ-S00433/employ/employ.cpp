#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=12;
int n,m,c[N],p[N];string s;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>s;s=" "+s;
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++)p[i]=i;
    int ans=0;
    do{
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='0')cnt++;
            else if(cnt>=c[p[i]])cnt++;
        }
        if(n-cnt>=m)ans++;
    }while(next_permutation(p+1,p+n+1));
    cout<<ans<<'\n';
    return 0;
}