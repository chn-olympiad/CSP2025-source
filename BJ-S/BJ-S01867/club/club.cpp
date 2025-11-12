#include <bits/stdc++.h>
using namespace std;

long long a[100005][3];
vector<long long> vc[5];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    priority_queue<long long, vector<long long>, greater<long long> > pq;
    long long T;
    cin >> T;
    while(T--){
        while(!pq.empty()) pq.pop();
        vc[1].clear();
        vc[2].clear();
        vc[3].clear();
        long long n, ans=0;
        cin >> n;
        for(long long i=1;i <= n;i++){
            for(long long j=1;j <= 3;j++){
                cin >> a[i][j];
            }
            if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) vc[1].push_back(i);
            else if(a[i][2] >= a[i][3]) vc[2].push_back(i);
            else vc[3].push_back(i);
        }
        for(long long j=1;j <= 3;j++){
            for(long long i : vc[j]){
                ans+=a[i][j];
            }
        }
        long long s=0;
        if(vc[1].size() > n/2) s=1;
        else if(vc[2].size() > n/2) s=2;
        else if(vc[3].size() > n/2) s=3;
        if(s == 0){
            cout << ans << "\n";
            continue;
        }
        for(long long i : vc[s]){
            if(s == 1){
                pq.push(a[i][s]-max(a[i][2], a[i][3]));
            }
            else if(s == 2){
                pq.push(a[i][s]-max(a[i][1], a[i][3]));
            }
            else if(s == 3){
                pq.push(a[i][s]-max(a[i][1], a[i][2]));
            }
        }
        for(long long i=n/2+1;i <= vc[s].size();i++){
            ans-=pq.top();
            pq.pop();
        }
        cout << ans << "\n";
    }
    return 0;
}