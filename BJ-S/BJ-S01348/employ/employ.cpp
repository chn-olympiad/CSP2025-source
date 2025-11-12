#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+5;
const int M=1e6+5;
const int mod=998244353;
int n,m,p[N],c[N];
string s;
bool checka() {
    for(int i=0;i<n;i++)
        if(s[i]!='1')return 0;
    return 1;
}
int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)cin>>c[i],p[i]=i;
    if(m==n) {
        if(checka()) {
            for(int i=1;i<=n;i++)
                if(c[i]==0)return printf("0\n"),0;
            LL res=1;
            for(int i=1;i<=n;i++)res=res*i%mod;
            printf("%lld\n",res);
            return 0;
        } else return printf("0\n"),0;
    }
    int ans=0;
    do {
        int cnt=0;
        for(int i=1;i<=n;i++) {
            if(cnt>=c[p[i]]||s[i-1]=='0')
                cnt++;
        }
        if(n-cnt>=m)ans++;
    }while(next_permutation(p+1,p+n+1));
    printf("%d\n",ans);
    return 0;
}
