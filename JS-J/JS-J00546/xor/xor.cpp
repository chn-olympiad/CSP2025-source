#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fin(s) freopen(s,"r",stdin)
#define fout(s) freopen(s,"w",stdout)
int N=500005;//N*log2(n)=1e7  O(max)=3e8
int n,a[500005],pre[500005],k,now,ans;
set<int> st;
signed main(){
    fin("xor.in");fout("xor.out");
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    rep(i,1,n){
        cin>>a[i];
        pre[i]=pre[i-1]^a[i];
    }
    rep(i,0,n){
        int f=pre[i]^k;
        if(!st.empty()){
            if(st.count(f)){
                //cout<<i<<'\n';
                ans++;
                st.clear();
            }
        }
        st.insert(pre[i]);
    }
    cout<<ans;

    return 0;
}
//running limit time 3e8
