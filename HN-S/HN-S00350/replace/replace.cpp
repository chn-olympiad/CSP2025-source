#include<bits/stdc++.h>
using namespace std;
using ll =long long;
using ull = unsigned long long;
using pll = pair<ll,ll>;
using pii = pair<int,int>;
using ar3 = array<int,3>;
#define fi first
#define se second
#define ep emplace
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define ffor(i,l,r) for(int i=(l),_=(r);i<=_;i++)
#define rfor(i,r,l) for(int i=(r),_=(l);i>=_;i--)
constexpr int N=2e5+100;
int n,q;
string s[N][2];
int main(){
  cin.tie(0)->ios::sync_with_stdio(0);
  freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);
  cin>>n>>q;
  ffor(i,1,n)cin>>s[i][0]>>s[i][1];
  ffor(i,1,n){
    string t1,t2;
    cin>>t1>>t2;
    int ans=0;
    int l1=t1.length(),l2=t2.length();
    if(l1!=l2)cout<<"0\n";
    else{
      cout<<"1\n";
    }
  }
  return 0;
}
//g++ -O2 code.cpp -o code -std=c++14 -Wall -Wextra -fsanitize=address,leak,undefined && time ./code 