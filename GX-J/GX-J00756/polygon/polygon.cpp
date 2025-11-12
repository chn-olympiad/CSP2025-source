#include<bits/stdc++.h>
template<typename T>
inline T read(){T t=0;bool f=0;char c=getchar();
    while(c<'0'||c>'9')f=c=='-',c=getchar();
    while(!(c<'0'||c>'9'))t*=10,t+=c-'0',c=getchar();
    return f?-t:t;
}
template<typename T>
inline void write(T t){
    if(t<0)putchar('-'),t=-t;
    if(t>9)write(t/10);
    putchar(t%10+'0');
}
using namespace std;
#define ll long long
const int MOD=998244353;
int n;
vector<int>a;
ll dfs(vector<int>tmp,ll sum){
    ll ans=(tmp.size()>2&&a[tmp.back()]>sum);
    for(ll i=tmp.empty()?0:tmp.back()+1;i<n;i++){
        tmp.emplace_back(i);
        if(tmp.size()>2&&a[i]>sum)ans=(ans+1)%MOD;
        ans=(ans+dfs(tmp,sum+a[i]))%MOD;
    }
    return ans;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    n=read<int>();
    a.resize(n);
    for(auto&i:a)i=read<int>();
    sort(a.begin(),a.end());
    write(dfs({},0));
    putchar('\n');
    return 0;
}