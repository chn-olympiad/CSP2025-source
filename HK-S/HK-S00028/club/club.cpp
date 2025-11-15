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
ifstream fin("club.in");
ofstream fout("club.out");

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n),c(n);
    int an=0,bn=0,cn=0;
    int ans=0;
    priority_queue<int> aa,bb,cc;
    rep(i,0,n){
        cin>>a[i]>>b[i]>>c[i];
        if (a[i]>=b[i]&&a[i]>=c[i]){ //a
            if (an<n/2){
                ans+=a[i];
                aa.push(max(b[i]-a[i],c[i]-a[i]));
                an++;
            }else{
                ans+=a[i];
                aa.push(max(b[i]-a[i],c[i]-a[i]));
                ans+=aa.top();
                aa.pop();
            }
        }else if (b[i]>=a[i]&&b[i]>=c[i]){ //b
            if (bn<n/2){
                ans+=b[i];
                bb.push(max(a[i]-b[i],c[i]-b[i]));
                bn++;
            }else{
                ans+=b[i];
                bb.push(max(a[i]-b[i],c[i]-b[i]));
                ans+=bb.top();
                bb.pop();
            }
        }else{ //c
            if (cn<n/2){
                ans+=c[i];
                cc.push(max(a[i]-c[i],b[i]-c[i]));
                cn++;
            }else{
                ans+=c[i];
                cc.push(max(a[i]-c[i],b[i]-c[i]));
                ans+=cc.top();
                cc.pop();
            }
        }
    }
    cout<<ans<<'\n';
}

signed main(){
  cin.tie(nullptr)->ios::sync_with_stdio(0);
  int t;
  cin>>t;
  while (t--) solve();
  return 0;
}