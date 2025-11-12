#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,c1,c2,c3,ind;
ll ans;
vector<ll> cmp[3];
ll mp[100218][3];
ll quickread(){
    char c = getchar();
    while(!isdigit(c)){c = getchar();}
    ll ans = 0;
    while(isdigit(c)){
        ans = ans*10+c-'0';
        c = getchar();
    }
    return ans;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    t = quickread();
    while(t--){
        for(int i = 1;i<=100000;++i)mp[i][0] = 0,mp[i][1] = 0,mp[i][2] = 0;
        cmp[0].clear(),cmp[1].clear(),cmp[2].clear();
        c1 = 0,c2 = 0,c3 = 0,ans = 0,ind = 0;
        n = quickread();
        for(int i = 1,m;i<=n;++i){
            mp[i][0] = quickread(),mp[i][1] = quickread(),mp[i][2] = quickread();
            m = max(max(mp[i][0],mp[i][1]),mp[i][2]);
            if(m == mp[i][0]){
                ++c1,ans+=m;
                cmp[0].push_back(min(m-mp[i][1],m-mp[i][2]));
            }
            else if(m == mp[i][1]){
                ++c2,ans+=m;
                cmp[1].push_back(min(m-mp[i][0],m-mp[i][2]));
            }
            else if(m == mp[i][2]){
                ++c3,ans+=m;
                cmp[2].push_back(min(m-mp[i][0],m-mp[i][1]));
            }
        }
        sort(cmp[0].begin(),cmp[0].end());
        sort(cmp[1].begin(),cmp[1].end());
        sort(cmp[2].begin(),cmp[2].end());
        int maxc = max(max(c1,c2),c3);
        int flag = 0;
        if(maxc == c1)flag = 0;
        if(maxc == c2)flag = 1;
        if(maxc == c3)flag = 2;
        while(maxc>(n/2)){
            maxc--,ans-=cmp[flag][ind++];
        }
        printf("%lld\n",ans);
    }
}
