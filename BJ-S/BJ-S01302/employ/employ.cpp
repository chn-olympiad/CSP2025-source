#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod=998244353;
int n,m;
int c[510];
string s;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    s=' '+s;
    for(int i=1;i<=n;i++)cin>>c[i];
    if(n<=12){
        int p[20];
        for(int i=1;i<=n;i++)p[i]=i;
        int ans=0;
        do{
            int cnt=0,sum=0;
            for(int i=1;i<=n;i++){
                if(cnt>=c[p[i]]){
                    cnt++;
                    continue;
                }
                if(s[i]-'0'){
                    sum++;
                }
                else cnt++;
            }
            if(sum>=m)ans++;
        }while(next_permutation(p+1,p+n+1));
        cout<<ans;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        cnt+=s[i]-'0';
    }
    if(cnt<m){
        cout<<0;
        return 0;
    }
    if(n==m){
        for(int i=1;i<=n;i++){
            if(c[i]==0){
                cout<<0;
                return 0;
            }
        }
        int mul=1;
        for(int i=1;i<=n;i++)mul=mul*i%mod;
        cout<<mul;
        return 0;
    }
    return 0;
}
