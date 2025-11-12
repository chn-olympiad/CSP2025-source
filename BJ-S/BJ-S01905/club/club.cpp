#include <bits/stdc++.h>
using namespace std;

int a[100005][4];

struct P{
    int id, val, now, to, to2;
};

bool operator <(P A,P B){
    return A.val > B.val;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        priority_queue <P> q;
        int cnt[3] = {0,0,0};
        int n, ans = 0;
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]&&a[i][1]>=a[i][2]){
                q.push({i,a[i][0]-a[i][1],0,1,2});
                ans+=a[i][0];
                cnt[0]++;
            }
            else if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]&&a[i][2]>=a[i][1]){
                q.push({i,a[i][0]-a[i][2],0,2,1});
                ans+=a[i][0];
                cnt[0]++;
            }
            else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]&&a[i][0]>=a[i][2]){
                q.push({i,a[i][1]-a[i][0],1,0,2});
                ans+=a[i][1];
                cnt[1]++;
            }
            else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]&&a[i][2]>=a[i][0]){
                q.push({i,a[i][1]-a[i][2],1,2,0});
                ans+=a[i][1];
                cnt[1]++;
            }
            else if(a[i][2]>=a[i][0]&&a[i][2]>=a[i][1]&&a[i][0]>=a[i][1]){
                q.push({i,a[i][2]-a[i][0],2,0,1});
                ans+=a[i][2];
                cnt[2]++;
            }
            else if(a[i][2]>=a[i][0]&&a[i][2]>=a[i][1]&&a[i][1]>=a[i][0]){
                q.push({i,a[i][2]-a[i][1],2,1,0});
                ans+=a[i][2];
                cnt[2]++;
            }
        }
        while(1){
            if(cnt[0]<=n/2&&cnt[1]<=n/2&&cnt[2]<=n/2){
                break;
            }
            P ch = q.top();
            q.pop();
            if(ch.to==3){
                continue;
            }
            if(cnt[ch.now]>n/2){
                ans -= ch.val;
                cnt[ch.now]--;
                cnt[ch.to]++;
                q.push({ch.id,a[ch.id][ch.to]-a[ch.id][ch.to2],ch.to,ch.to2,3});
            }
        }
        cout << ans << "\n";
    }
    return 0;
}