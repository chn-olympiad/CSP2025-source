#include<bits/stdc++.h>
using namespace std;
#define int long long
int cnt[4],a[100005][4],cho[100005];
priority_queue<int>q;
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        memset(cnt,0,sizeof(cnt));
        while(!q.empty()){
            q.pop();
        }
        int n,ans;
        cin>>n;
        ans = 0;
        for(int i = 1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            int maxn;
            maxn = max(max(a[i][1],a[i][2]),a[i][3]);
            ans = ans+maxn;
            for(int j = 1;j<=3;j++){
                if(maxn == a[i][j]){
                    cho[i] = j;
                    cnt[j]++;
                    break;
                }
            }
        }
        int w;
        w = 0;
        for(int i = 1;i<=3;i++){
            if(cnt[i]*2>n){
                w = i;
                break;
            }
        }
        if(!w){
            cout<<ans<<"\n";
            continue;
        }
        for(int i = 1;i<=n;i++){
            if(cho[i] == w){
                int maxn;
                maxn = 0;
                for(int j = 1;j<=3;j++){
                    if(j == w){
                        continue;
                    }
                    maxn = max(maxn,a[i][j]);
                }
                q.push(maxn-a[i][w]);
            }
        }
        for(int i = 1;i<=cnt[w]-n/2;i++){
            ans = ans+q.top();
            q.pop();
        }
        cout<<ans<<"\n";
    }
    return 0;
}
