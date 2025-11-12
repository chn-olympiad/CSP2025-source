#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+5,mod=998244353;
int n,m,all,c[N],p[N];
string s;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    cin>>s;
    for(int i=1;i<=n;i++)
        scanf("%lld",&c[i]);
    for(int i=1;i<=n;i++)
        p[i]=i;
    do{
        int cnt=0,now=0;
        for(int i=1;i<=n;i++){
            if(now<c[p[i]]&&s[i-1]=='1')
                cnt++;
            else
                now++;
        }
        if(cnt>=m)
            all=(all+1)%mod;
    }while(next_permutation(p+1,p+n+1));
    printf("%lld",all);
    return 0;
}
