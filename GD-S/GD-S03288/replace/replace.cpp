#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ep emplace
#define eb emplace_back 
#define fr(a,b,c) for(int (a) = (b);(a) <= (c);a ++)
using namespace std;
const int N = 201000;
int n,q,ans[N],cnting,sx[N],sy[N],tx[N],ty[N],c[6000000],cnt,ch[7000000][30],bh[7000000];
string s[N][2],t[N][2];
bool xzB = true;
map<pair<string,string>,int> mp;
vector<int> up[N],qr[N],cc[N]; 
void upd_f(int x,int y){
  // printf("upd %d %d\n",x,y);
  if(x) for(;x < N;x += x & -x) c[x] += y;
  else c[0] += y;
}
int qry_f(int x){
  // printf("qry %d\n",x);
  int rt = c[0];
  for(;x > 0;x -= x & -x) rt += c[x];
  return rt;
}
void workB(){
  fr(i,1,cnting){
    sort(qr[i].begin(),qr[i].end(),[](int xx,int yy){
      return tx[xx] < tx[yy];
    });
    sort(up[i].begin(),up[i].end(),[](int xx,int yy){
      return sx[xx] < sx[yy];
    });
    int it = 0;
    for(auto j : qr[i]){
      while(it < up[i].size() && sx[up[i][it]] <= tx[j]) upd_f(sy[up[i][it]],1),it ++;
      ans[j] = qry_f(ty[j]);
    }
    while(it) upd_f(sy[up[i][-- it]],-1);
  }
  fr(i,1,q) printf("%d\n",ans[i]);
};
int main(){
  freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> q;
  fr(i,1,n){
    cin >> s[i][0] >> s[i][1];
    for(int j = 0;j < s[i][0].size();j ++){
      if(s[i][0][j] == s[i][1][j]) sx[i] ++;
      else break;
    }
    for(int j = s[i][0].size() - 1;~j;j --){
      if(s[i][0][j] == s[i][1][j]) sy[i] ++;
      else break;
    }
    int len = s[i][0].size() - sx[i] - sy[i],bh;
    pair<string,string> tmp = {s[i][0].substr(sx[i],len),s[i][1].substr(sx[i],len)};
    // cout << tmp.first << ' ' << tmp.second << endl;
    if(!mp[tmp]) bh = mp[tmp] = ++ cnting;
    else bh = mp[tmp];
    up[bh].eb(i);
    // printf("%d %d %d\n",sx[i],sy[i],bh);
  }
  fr(i,1,q){
    cin >> t[i][0] >> t[i][1];
    if(t[i][0].size() != t[i][1].size()) continue;
    for(int j = 0;j < t[i][0].size();j ++){
      if(t[i][0][j] == t[i][1][j]) tx[i] ++;
      else break;
    }
    for(int j = t[i][0].size() - 1;~j;j --){
      if(t[i][0][j] == t[i][1][j]) ty[i] ++;
      else break;
    }
    int len = t[i][0].size() - tx[i] - ty[i],bh;
    pair<string,string> tmp = {t[i][0].substr(tx[i],len),t[i][1].substr(tx[i],len)};
    // cout << tmp.first << ' ' << tmp.second << endl;
    if(!mp[tmp]) continue;
    else bh = mp[tmp];
    qr[bh].eb(i);
    // printf("%d %d %d\n",tx[i],ty[i],bh);
  }
  fr(i,1,n){
    fr(j,0,1){
      int cnt = 0;
      for(auto c : s[i][j]){
        if(c > 'b') xzB = false;
        if(c == 'b') cnt ++;
      }
      if(cnt != 1) xzB = false;
    }
  }
  fr(i,1,q){
    fr(j,0,1){
      int cnt = 0;
      for(auto c : t[i][j]){
        if(c > 'b') xzB = false;
        if(c == 'b') cnt ++;
      }
      if(cnt != 1) xzB = false;
    }
  }
  if(xzB){workB();return 0;}
  fr(i,1,cnting){
    cnt = 0,bh[0] = 0;
    int tot = 0;
    vector<int> ck;
    for(auto j : up[i]){
      if(!sx[j]){ck.eb(j);break;}
      int u = 0;
      for(int k = sx[j] - 1;~k;k --){
        int c = s[j][0][k] - 'a';
        if(!ch[u][c]) ch[u][c] = ++ cnt,bh[cnt] = 0;
        u = ch[u][c];
      }
      if(!bh[u]) bh[u] = ++ tot,cc[tot].clear();
      cc[bh[u]].eb(j);
    }
    for(auto j : qr[i]){
      int u = 0;
      for(int k = tx[j] - 1;~k;k --){
        int c = t[j][0][k] - 'a';
        if(!ch[u][c]) break;
        u = ch[u][c];
        if(bh[u]) for(auto l : cc[bh[u]]) ck.eb(l);
      }
      for(auto k : ck){
        bool suc = true;
        if(sy[k] >= ty[j]) suc = false;
        else{
          int ss = s[k][0].size() - sy[k],ts = t[j][0].size() - ty[j];
          fr(i,0,sy[k] - 1){
            if(s[k][0][ss + i] != t[k][0][ts + i]){
              suc = false;
              break;
            }
          }
        }
        if(suc) ans[j] ++;
      }
      for(int k = tx[j] - 1;~k;k --){
        int c = t[j][0][k] - 'a';
        if(!ch[u][c]) break;
        u = ch[u][c];
        if(bh[u]) for(auto l : cc[bh[u]]) ck.pop_back();
      }
    }
  }
  fr(i,1,q) printf("%d\n",ans[i]);
  return 0;
}