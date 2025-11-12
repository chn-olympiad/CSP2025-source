#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct stu{
    int v,id;
    bool operator<(stu &b){
        return v>b.v;
    }
}t[3*N];
int n,sum[4];
bool v[N];
void solve(){
    sum[1]=sum[2]=sum[3]=0;
    memset(v,0,sizeof v);
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            scanf("%d",&t[3*(i-1)+j].v);
            t[3*(i-1)+j].id=j;
        }
    }
    //cout << n << endl;
    long long ans=0;
    int cnt=0;
    sort(t+1,t+3*n+1);
    for(int i=1;i<=3*n;i++){
        if(sum[t[i].id]>=n/2||v[(i+2)/3]) continue;
        ans+=t[i].v;
        ++sum[t[i].id];
        ++cnt;
        v[(i+2)/3]=1;
        if(cnt==n) break;
    }
    //cout << 'y' << endl;
    cout << ans << endl;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
