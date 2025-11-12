#include <bits/stdc++.h>
using namespace std;
bool cmd(const pair<int,int>& a,const pair<int,int>& b){
    if(a.first == b.first){
        return a.second > b.second;
    }
    return a.first > b.first;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    vector<long long> sss;
    while(t--){
        long long n;
        cin >> n;
        bool l = false;
        vector<vector<pair<long long,long long>>> g(n+1,vector<pair<long long,long long>>(6));
        for(long long i = 1;i<=n;i++){
            long long a,b,c;
            cin >> a >> b >> c;
            if(b != 0 || c != 0)l = true;
            g[i][0] = pair<long long,long long>({a,1});
            g[i][1] = pair<long long,long long>({b,2});
            g[i][2] = pair<long long,long long>({c,3});
        }
        for(long long i = 1;i<=n;i++){
            sort(g[i].begin(),g[i].end(),cmd);
        }
        int sum = 0;
        vector<long long> o(4);
        vector<vector<long long> > c(4);
        for(long long i = 1;i<=n;i++){
            long long j = 0;
            if(o[g[i][j].second] >= n/2){
                if(c[j][0] < g[i][j].first-g[i][j+1].first){
                    sum-=c[j][0];
                    o[g[i][j].second]--;
                    c[j][0] = g[i][j].first-g[i][j+1].first;
                }else if(c[j][0] >= g[i][j].first-g[i][j+1].first){
                    j++;
                    if(c[j][0] < g[i][j].first-g[i][j+1].first){
                        sum-=c[j][0];
                        o[g[i][j].second]--;
                        c[j][0] = g[i][j].first-g[i][j+1].first;
                    }
                }
            }
            sum+=g[i][j].first;
            o[g[i][j].second]++;
            c[j].push_back(g[i][j].first-g[i][j+1].first);
            sort(c[j].begin(),c[j].end());
        }
        sss.push_back(sum);
    }
    for(long long i : sss){
        cout << i << endl;
    }
    return 0; 
}

