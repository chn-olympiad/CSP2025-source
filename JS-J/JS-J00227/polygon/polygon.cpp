//polygon
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll a[5005];
set<string>s;
bool flag[5005];
ll maxs=LONG_LONG_MIN;
void dfs(ll dep,set<int> dfss,ll maxlen,ll sumlen){
        if(maxlen*2<sumlen){
            auto it=dfss.begin();
            string str;
            for(;it!=dfss.end();it++){
                str=str+(char)(*it+'0');
            }
            s.insert(str);
        }
        for(ll i=1;i<=n;i++){
            if(!flag[i]){
                flag[i]=1;
                set<int>ls=dfss;
                ls.insert(i);
                dfs(dep+1,ls,max(maxlen,a[i]),sumlen+a[i]);
                flag[i]=0;
            }
        }
    }
int main(){
freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        maxs=max(a[i],maxs);
    }
    set<int>ls;
    dfs(1,ls,0,0);
    printf("%lld",(ll)((ll)(s.size())%998244353));
    return 0;
}
//rp++
/*
5
2 2 3 8 10
*/
