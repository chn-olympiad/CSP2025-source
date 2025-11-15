#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pb push_back
#define rep(x,y,z) for(int x=y;x<z;x++)
#define cin fin
#define cout fout
ifstream fin("replace.in");
ofstream fout("replace.out");
const int h1=3141592653;
const int h2=1000000007;
unsigned seed=31415923;
mt19937 gen(seed);
vector<int> spe(30);

int qry1(int l, int r, vector<int> &pre, int t){
    int res=0;
    if (t==1){
        res+=pre[r];
        res+=h1;
        if (l>0) res-=pre[l-1];
        res%=h1;
    }else{
        res+=pre[r];
        res+=h2;
        if (l>0) res-=pre[l-1];
        res%=h2;
    }
    return res;
}

int qry2(int l, int r, vector<int> &mou, vector<int> &pre, int t){
    int res=0;
    if (t==1){
        res+=mou[r];
        res+=h1;
        if (l>0) res-=mou[l-1];
        res+=h1;
        res-=(l*qry1(l,r,pre,t))%h1;
        res%=h1;
    }else{
        res+=mou[r];
        res+=h2;
        if (l>0) res-=mou[l-1];
        res+=h2;
        res-=(l*qry1(l,r,pre,t))%h2;
        res%=h2;
    }
    return res;
}

signed main(){
  cin.tie(nullptr)->ios::sync_with_stdio(0);
  rep(i,0,30){
      spe[i]=gen()%1000;
  }
  sort(all(spe));
  spe.resize(unique(all(spe))-spe.begin());
  shuffle(all(spe),gen);
  int n,q;
  cin>>n>>q;
  vector<string> s(n*2);
  vector<int> p1(n*2,0),m1(n*2,0),p2(n*2,0),m2(n*2,0);
  vector<int> ll(n),rr(n);
  vector<int> len(n*2);
  rep(i,0,n*2){
      cin>>s[i];
      len[i]=s[i].length();
      rep(j,0,len[i]){
          int val=spe[s[i][j]-'a'];
        p1[i]=(p1[i]+val)%h1;
        p2[i]=(p2[i]+val)%h1;
        m1[i]=(m1[i]+val*(j+1))%h1;
        m2[i]=(m2[i]+val*(j+1))%h1;
      }
  }
  rep(i,0,n){
      ll[i]=len[i*2];
      rr[i]=-1;
      rep(j,0,len[i*2]){
          if (s[i*2][j]!=s[i*2+1][j]){
              ll[i]=min(ll[i],j);
              rr[i]=max(rr[i],j);
          }
      }
      if (rr[i]==-1) ll[i]=-1;
  }
  while (q--){
      string t1,t2;
      cin>>t1>>t2;
      int m=t1.length();
      int tl=m,tr=-1;
      vector<int> ap1(m),ap2(m),am1(m),am2(m);
      vector<int> bp1(m),bp2(m),bm1(m),bm2(m);
      rep(i,0,m){
          if (t1[i]!=t2[i]){
            tl=min(tl,i);
            tr=max(tr,i);
          }
          int val=spe[t1[i]-'a'];
          ap1[i]=ap2[i]=val;
          am1[i]=(val*(i+1))%h1;
          am2[i]=(val*(i+1))%h2;
          if (i>0){
              ap1[i]=(ap1[i]+ap1[i-1])%h1;
              ap2[i]=(ap2[i]+ap2[i-1])%h2;
              am1[i]=(am1[i]+am1[i-1])%h1;
              am2[i]=(am2[i]+am2[i-1])%h2;
          }
          val=spe[t2[i]-'a'];
          bp1[i]=bp2[i]=val;
          bm1[i]=(val*(i+1))%h1;
          bm2[i]=(val*(i+1))%h2;
          if (i>0){
              bp1[i]=(bp1[i]+bp1[i-1])%h1;
              bp2[i]=(bp2[i]+bp2[i-1])%h2;
              bm1[i]=(bm1[i]+bm1[i-1])%h1;
              bm2[i]=(bm2[i]+bm2[i-1])%h2;
          }
      }
      int ans=0;
      rep(i,0,n){
          if (ll[i]==-1) continue;
          if (rr[i]-ll[i]!=tr-tl) continue;
          if (ll[i]>tl) continue;
          if (len[i*2]-rr[i]>m-tr) continue;
          int bl=tl-ll[i],br=bl+len[i*2]-1;
          if (p1[i*2]==qry1(bl,br,ap1,1)){
              if (p2[i*2]==qry1(bl,br,ap2,2)){
                if (m1[i*2]==qry2(bl,br,am1,ap1,1)){
                    if (m2[i*2]==qry2(bl,br,am2,ap2,2)){
                        if (p1[i*2+1]==qry1(bl,br,bp1,1)){
                            if (p2[i*2+1]==qry1(bl,br,bp2,2)){
                                if (m1[i*2+1]==qry2(bl,br,bm1,bp1,1)){
                                    if (m2[i*2+1]==qry2(bl,br,bm2,bp2,2)){
                                        ans++;
                                    }
                                }
                            }
                        }
                    }
                }
              }
          }
      }
      cout<<ans<<'\n';
  }
  return 0;
}
