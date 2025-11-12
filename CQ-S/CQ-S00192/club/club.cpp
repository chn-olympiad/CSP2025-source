#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
#define mid ((l+r)>>1)
#define ls k<<1
#define rs k<<1|1
#define lowbit(x) (x&(-x))
#define popcount __builtin_popcount
using namespace std;
int rd(){
    int x=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f*=-1;
    for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+(ch-'0');
    return x*f;
}
const int N=1e5+5,INF=0x3f3f3f3f3f3f3f3f;
int a[3][N],n,ans;
vector<int> vec[3],tmp;
void solve(){
    n=rd();
    for(int i=1;i<=n;i++){
        a[0][i]=rd(),a[1][i]=rd(),a[2][i]=rd();
        if(a[0][i]>=max(a[1][i],a[2][i])) vec[0].p_b(i),ans+=a[0][i];
        else if(a[1][i]>=max(a[0][i],a[2][i])) vec[1].p_b(i),ans+=a[1][i];
        else vec[2].p_b(i),ans+=a[2][i];
    }
    for(auto o : {0,1,2})if((int)vec[o].size()>n/2){
        int delta=vec[o].size()-n/2;
        for(auto i : vec[o]){
            int mx=-INF;
            for(auto op : {0,1,2}) if(op!=o) mx=max(mx,-a[o][i]+a[op][i]);
            tmp.p_b(mx); 
        }
        sort(tmp.begin(),tmp.end());
        while(delta--) ans+=tmp.back(),tmp.pop_back();
        break;
    }
    printf("%lld\n",ans);
}
void clean(){
    tmp.clear();ans=0;
    vec[0].clear(),vec[1].clear(),vec[2].clear();
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=rd();
    while(T--) solve(),clean();
    return 0;
}
//g++ club.cpp -o club -std=c++14 -O2 -Wall -fsanitize=address,undefined