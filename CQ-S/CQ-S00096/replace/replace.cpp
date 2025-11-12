#include<bits/stdc++.h>
using namespace std;
#define mod1 19491001
#define mod2 998244853
#define P 103
#define par pair<int, int>
#define parr pair<par, par>
#define rpar pair<parr, parr>
struct node{int now, x, y;}lst[200005];
struct ques{int now, x, y, id;}qu[200005];
struct nodee{int x, y, id;};
int n, q, lef[200005], rig[200005], len, lenq, Ans[200005], st[400005], id, idd;
par Lef[200005], Rig[200005];
rpar now[200005];
inline void add(par &x, char c){
    x.first=(1ll*x.first*P+c-'a'+1)%mod1;
    x.second=(1ll*x.second*P+c-'a'+1)%mod2;
}
map<int, int>mp, mpp;
vector<nodee>g[400005];
bool cmp(nodee a, nodee b){return a.x<b.x||(a.x==b.x&&a.y<b.y)||(a.x==b.x&&a.y==b.y&&a.id<b.id);}
int lowbit(int x){return x&(-x);}
void add(int x, int c){for(int i=x; i<=idd; i+=lowbit(i))st[i]+=c;}
int ask(int x){int sum=0;for(int i=x; i>=1; i-=lowbit(i))sum+=st[i];return sum;}
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    if(1ll*n*q<=1000000){
        for(int i=1; i<=n; i++){
            string s, t;cin >> s >> t;
            int minn=INT_MAX, maxx=-1;
            for(int i=0; i<s.length(); i++){
                if(s[i]!=t[i])minn=min(minn, i), maxx=max(maxx, i);
            }lef[i]=-1;
            if(maxx==-1)continue;
            par has={0, 0}, hass={0, 0};
            for(int i=minn; i<=maxx; i++){
                add(has, s[i]);add(hass, t[i]);
            }
            par hah={0, 0}, hahh={0, 0};
            for(int i=minn-1; i>=0; i--)add(hah, s[i]);
            for(int i=maxx+1; i<s.length(); i++)add(hahh, t[i]);
            now[i]={{has, hass}, {hah, hahh}};
            lef[i]=minn;rig[i]=s.length()-1-maxx;
        }
        while(q--){
            string s, t;cin >> s >> t;int ans=0;
            if(s.length()!=t.length())puts("0");
            else{
                int minn=INT_MAX, maxx=-1;
                for(int i=0; i<s.length(); i++){
                    if(s[i]!=t[i])minn=min(minn, i), maxx=max(maxx, i);
                }
                par has={0, 0}, hass={0, 0};
                for(int i=minn; i<=maxx; i++){
                    add(has, s[i]);add(hass, t[i]);
                }parr tmp={has, hass};
                for(int i=minn-1, t=1; i>=0; i--, t++)Lef[t]=Lef[t-1], add(Lef[t], s[i]);
                for(int i=maxx+1, t=1; i<s.length(); i++, t++)Rig[t]=Rig[t-1], add(Rig[t], s[i]);
                int le=minn, ri=s.length()-1-maxx;
                for(int i=1; i<=n; i++){
                    if(lef[i]==-1||lef[i]>le||rig[i]>ri)continue;
                    rpar tmpp={tmp, {Lef[lef[i]], Rig[rig[i]]}};
                    if(tmpp==now[i])ans++;
                }cout << ans << '\n';
            }
        }
    }
    else{
        for(int i=1; i<=n; i++){
            string s, t;cin >> s >> t;
            int minn=INT_MAX, maxx=-1;
            for(int i=0; i<s.length(); i++){
                if(s[i]=='b')minn=i;
                if(t[i]=='b')maxx=i;
            }lef[i]=-1;
            if(minn==maxx)continue;
            int leff=min(minn, maxx), rigg=s.length()-1-max(minn, maxx);
            lst[++len]={minn-maxx, leff, rigg};
            mp[minn-maxx]=1;mpp[rigg]=1;
        }        
        for(int i=1; i<=q; i++){
            string s, t;cin >> s >> t;
            if(s.length()!=t.length())continue;
            int minn=INT_MAX, maxx=-1;
            for(int i=0; i<s.length(); i++){
                if(s[i]=='b')minn=i;
                if(t[i]=='b')maxx=i;
            }
            int leff=min(minn, maxx), rigg=s.length()-1-max(minn, maxx);
            qu[++lenq]={minn-maxx, leff, rigg, i}; 
            mp[minn-maxx]=1;mpp[rigg]=1;
        }
        for(auto i:mp)mp[i.first]=++id;
        for(auto i:mpp)mpp[i.first]=++idd;
        for(int i=1; i<=len; i++){
            lst[i].now=mp[lst[i].now];
            lst[i].y=mpp[lst[i].y];
            g[lst[i].now].push_back({lst[i].x, lst[i].y, 0});
        }
        for(int i=1; i<=lenq; i++){
            qu[i].now=mp[qu[i].now];
            qu[i].y=mpp[qu[i].y];
            g[qu[i].now].push_back({qu[i].x, qu[i].y, qu[i].id});
        }
        for(int i=1; i<=id; i++)sort(g[i].begin(), g[i].end(), cmp);
        for(int i=1; i<=id; i++){
            for(auto j:g[i]){
                if(!j.id)add(j.y, 1);
                else Ans[j.id]=ask(j.y);
            }
            for(auto j:g[i])if(!j.id)add(j.y, -1);
        }
        for(int i=1; i<=q; i++)cout << Ans[i] << '\n';
    }
    return 0;
}