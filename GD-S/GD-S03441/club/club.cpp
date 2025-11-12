#include<bits/stdc++.h>
using namespace std;
const int N = 2e2+4,M=1e5+5;
typedef long long ll;
int f[N][N][N],a[N],b[N],c[N];
struct node{
    int idx,val;
    friend bool operator<(node x,node y){
        return x.val < y.val;
    }
};
void sol(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        // cout<<a[i]<<' '<<b[i]<<' '<<c[i]<<' ';
    }
    bool is1=1,is2=1;
    for(int i=1;i<=n;i++){
        if(b[i] > 0) is2=0;
        if(c[i] >0) is1=is2= 0;
    }
    if(is2){
        sort(a+1,a+n+1);
        int ans =0;
        for(int i=n;i > n/2;i--){
            ans += a[i];
        }
        cout<<ans<<'\n';
    }
    else if(is1){
        // cout<<"!";
        priority_queue<node> q;
        for(int i=1;i<=n;i++){
            q.push({i,a[i] - b[i]});
        }
        ll ans=0;
        for(int i=1;i<=n/2;i++){
            ans += a[q.top().idx];
            q.pop();
        }
        for(int i=1;i<=n/2;i++){
            ans += b[q.top().idx];
            q.pop();
        }
        cout<<ans<<'\n';
    }
    else{
        memset(f,0,sizeof f);
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int s1 = 0;s1 <= n/2;s1 ++){
                for(int s2 = 0;s2 <=n/2;s2++) {
                    int s3 = i - s1-s2-1;
                    if(s3>=0 && s3 <= n/2 && s1 + s2 + s3 == i-1){
                        if(s1 + 1 <= n/2){
                            f[s1+1][s2][s3] = max(f[s1+1][s2][s3],f[s1][s2][s3] + a[i]);
                            ans = max(ans,f[s1+1][s2][s3]);
                        }
                        if(s2+1<=n/2){
                            f[s1][s2+1][s3] = max(f[s1][s2+1][s3],f[s1][s2][s3] + b[i]);
                            ans = max(ans,f[s1][s2+1][s3]);
                        }
                        if(s3+1<=n/2){
                            f[s1][s2][s3+1] = max(f[s1][s2][s3+1],f[s1][s2][s3] + c[i]);
                            ans = max(ans,f[s1][s2][s3+1]);
                        }
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        sol();
    }
    return 0;
}