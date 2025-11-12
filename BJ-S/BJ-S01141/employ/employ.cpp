#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod=998244353;
int n,m,c[510],ans;
char t[510];
bool v[510];

void dfs(int step,int a1,int b1){
    if(step==n+1){
        int x=0,cn=0;
        for(int i=1;i<=n;i++){
            if(!v[i]||c[i]<=x)x++;
            else cn++;
        }
        if(cn>=m)ans++,ans%=mod;
        else{
            printf("%lld",ans);
            exit(0);
        }
    }
    if(a1){
        v[step]=1;
        dfs(step+1,a1-1,b1);
    }
    if(b1){
        v[step]=0;
        dfs(step+1,a1,b1-1);
    }
}

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    bool f=1;
    string s;
    cin >> s;
    int cnt1=0,cnt2=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0')f=0,cnt1++;
        else cnt2++;
    }
    int c1=0,c2=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&c[i]);
        if(c[i])c1++;
        if(c[i]==0&&c1!=i)c2++;
    }
    if(n-c2<m){
        printf("0");
        return 0;
    }
    if(f==1){
        int mul=1ll;
        for(int i=2;i<=n;i++)mul=(mul*i)%mod;
        cout << mul;
    }else{
        dfs(1,cnt2,cnt1);
        printf("%lld",ans);
    }
}
