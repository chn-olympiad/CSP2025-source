#include<bits/stdc++.h>

#define int long long
#define rep(i,l,r) for(int i = l;i <= r;i ++)
#define dep(i,l,r) for(int i = l;i >= r;i --)
#define mem(x,y) memset(x,y,sizeof(x))

using namespace std;

int read(){
    int s = 0,w = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-')w = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9')s = s * 10 + ch - '0',ch = getchar();
    return s * w;
}

int n,m;
char s1[5000010],s2[5000010];
int len;
pair <int,int> a[200010][2];
int cnt;
int bac[10010];//id对应的长度
const int bas1 = 1737,bas2 = 917;
const int mod = 1e9 + 7;

unordered_map <int ,int> mp[3010];//pair两个哈希值，数组是长度
map <int,int> to;//一个长度对应的id

struct Hash{
    int hsh1[5000010];
    int hsh2[5000010];
    int hsh3[5000010];
    int hsh4[5000010];
    int pw1[5000010];
    int pw2[5000010];

    void init(){
        pw1[0] = pw2[0] = 1;
        rep(i,1,5000000){
            pw1[i] = (pw1[i - 1] * bas1 % mod);
            pw2[i] = (pw2[i - 1] * bas2 % mod);
        }
    }

    pair <int,int> get1(){
        int hs1 = 0,hs2 = 0;
        rep(i,1,len){
           // cout<<"i = "<<i<<",s1[i] = "<<(int)(s1[i])<<endl;
            hs1 = (hs1 * bas1 % mod + s1[i]) % mod;
            hs2 = (hs2 * bas2 % mod + s1[i]) % mod;
        }
        return {hs1,hs2};
    }

    pair <int,int> get2(){
        int hs1 = 0,hs2 = 0;
        rep(i,1,len){
            hs1 = (hs1 * bas1 % mod + s2[i]) % mod;
            hs2 = (hs2 * bas2 % mod + s2[i]) % mod;
        }
        return {hs1,hs2};
    }

    void gener(){
        rep(i,1,len){
            hsh1[i] = (hsh1[i - 1] * bas1 % mod + s1[i]) % mod;
            hsh2[i] = (hsh2[i - 1] * bas2 % mod + s1[i]) % mod;
            hsh3[i] = (hsh3[i - 1] * bas1 % mod + s2[i]) % mod;
            hsh4[i] = (hsh4[i - 1] * bas2 % mod + s2[i]) % mod;
        }
    }

    pair <int,int> qry1(int l,int r){return {(hsh1[r] - hsh1[l - 1] * pw1[r - l + 1] % mod + mod) % mod,(hsh2[r] - hsh2[l - 1] * pw2[r - l + 1] % mod + mod) % mod};}

    pair <int,int> qry2(int l,int r){return {(hsh3[r] - hsh3[l - 1] * pw1[r - l + 1] % mod + mod) % mod,(hsh4[r] - hsh4[l - 1] * pw2[r - l + 1] % mod + mod) % mod};}
}hsh;

inline int getv(int a,int b,int c,int d){return (a * hsh.pw1[3] % mod + b * hsh.pw1[2] % mod + c * hsh.pw1[1] % mod + d) % mod;}

void solve(){
    hsh.gener();
    int ans = 0;
    int lp = -1,rp = -1;
    rep(i,1,len)if(s1[i] != s2[i]){lp = i;break;}
    dep(i,len,1)if(s1[i] != s2[i]){rp = i;break;}
    int need = rp - lp + 1;//至少需要更换的长度
    rep(id,1,cnt){
        int p = bac[id];
        if(p < need)continue;
       // cout<<"p = "<<p<<endl;
        rep(i,max(1ll,rp - p + 1),min(lp,len - p + 1)){
            int j = i + p - 1;
            //[i,j]是即将更换的区间
            if(!(i <= lp && j >= rp))continue;
           // cout<<"i = "<<i<<",j = "<<j<<",add = "<<mp[id][{hsh.qry1(i,j),hsh.qry2(i,j)}]<<endl;
           // cout<<"哈希 = "<<hsh.qry1(i,j).first<<" "<<hsh.qry1(i,j).second<<endl;
          //  {hsh.qry1(i,j),hsh.qry2(i,j)}
            pair <int,int> x,y;
            x = hsh.qry1(i,j);
            y = hsh.qry2(i,j);
            int v1,v2,v3,v4;
            v1 = x.first,v2 = x.second,v3 = y.first,v4 = y.second;
            ans += mp[id][getv(v1,v2,v3,v4)];
        }
    }
    printf("%lld\n",ans);
}

signed main(){
     freopen("replace.in","r",stdin);
     freopen("replace.out","w",stdout);
    //int ss11 = clock();
    hsh.init();
    cin>>n>>m;
    rep(i,1,n){
        scanf("%s",s1 + 1);
        scanf("%s",s2 + 1);
        len = strlen(s1 + 1);
        a[i][0] = hsh.get1();
        a[i][1] = hsh.get2();
        if(!to.count(len))to[len] = ++ cnt,bac[cnt] = len;
        int id = to[len];
        int v1,v2,v3,v4;
        v1 = a[i][0].first,v2 = a[i][0].second,v3 = a[i][1].first,v4 = a[i][1].second;
        mp[id][getv(v1,v2,v3,v4)] ++;
    }
   // cout<<a[3][0].first<<" "<<a[3][0].second<<endl;
    rep(pp,1,m){
        scanf("%s",s1 + 1);
        scanf("%s",s2 + 1);
        len = strlen(s1 + 1);
        solve();
    }
  //  cout<<"time : "<<clock() - ss11;
}
