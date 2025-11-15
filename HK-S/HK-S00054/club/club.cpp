#include<bits/stdc++.h>
using namespace std;
#define int long long
struct info{
    int x, d, num, c, m;
    bool operator<(const info& other) const {
        return d<other.d;
    }
};
int solve(){
    int n;
    int a, b, c;
    cin>>n;
    priority_queue<info> pq;
    for(int i=1;i<=n;i++){
        cin>>a>>b>>c;
        pq.push({a,a-max(b,c),i,0,max(b,c)});
        pq.push({b,b-max(a,c),i,1,max(a,c)});
        pq.push({c,c-max(a,b),i,2,max(a,b)});
    }
    int cnt=0, ans=0;
    bool chosen[n+1];
    int club[3];
    club[0]=club[1]=club[2]=0;
    fill(chosen, chosen+n+1, 0);
    while(!pq.empty()&&cnt!=n){
        info res = pq.top();
        pq.pop();
        if(chosen[res.num]||club[res.c]==n/2) continue;
        ans+=res.x;
        cnt++;
        chosen[res.num] = 1;
        club[res.c]++;
    }
    return ans;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<'\n';
    }
    return 0;
}
