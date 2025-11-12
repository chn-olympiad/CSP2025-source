#include <bits/stdc++.h>
using namespace std;
bool cmp2(vector<int> a,vector<int> b){return max({a[1]-a[2],a[1]-a[0],a[1]}) < max({b[1]-b[2],b[1]-b[0],b[1]});}


int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;cin >> t;
    for(int cs = 0;cs<t;cs++){
        long long n,sum = 0;cin >> n;
        vector<vector<vector<int>>> s;
        s.push_back({});s.push_back({});s.push_back({});
        int m0,m1,m2;
        for(int i = 0;i < n;i++){
            cin >> m0 >> m1 >> m2;
            s[1].push_back({m0,m1,m2});sum+=m1;
        }
        sort(s[1].begin(),s[1].end(),cmp2);
        for(int i = 0;i < n;i++){
            if(s[1][0][2] >= s[1][0][0] and (s[1][0][1] <= s[1][0][2] or s[1].size() > n/2)){
                if(s[2].size() < n/2){
                    s[2].push_back(s[1][0]);
                    sum=sum-s[1][0][1]+s[1][0][2];
                }else if(s[1][0][1] <= s[1][0][0]){
                    s[0].push_back(s[1][0]);
                    sum=sum-s[1][0][1]+s[1][0][0];
                }else{
                    s[1].push_back(s[1][0]);
                }
            }else if(s[1][0][1] <= s[1][0][0] or s[1].size() > n/2){
                if(s[0].size() < n/2){
                    s[0].push_back(s[1][0]);
                    sum=sum-s[1][0][1]+s[1][0][0];
                }else if(s[1][0][1] <= s[1][0][2]){
                    s[2].push_back(s[1][0]);
                    sum=sum-s[1][0][1]+s[1][0][2];
                }else{
                    s[1].push_back(s[1][0]);
                }
            }else{
                s[1].push_back(s[1][0]);
            }
            s[1].erase(s[1].begin());
        }
        cout << ' ' << sum << endl;
    }
    return 0;
}
