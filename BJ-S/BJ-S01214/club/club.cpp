#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct member{
    int id;
    int sat[3] = {0, 0, 0};
    int pri[3] = {0, 0, 0};
    int mad = 0;
    bool operator < (const member &oth) const {
        return mad > oth.mad;
    }
} s[100003];
bool cmp(int s1, int s2);
priority_queue<member, vector<member>, less<member> > apar[3];
int n, tt, cnt, cnd, cur, ans;
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> tt;
    while(tt--){
        cin >> n;
        for(int i = 0; i < n; i++){
            s[i].id = i;
            cin >> s[i].sat[0] >> s[i].sat[1] >> s[i].sat[2];
            cnt = -1, cur = -1, cnd = -1;
            for(int j = 0; j < 3; j++){
                if(s[i].sat[j] > cur){
                    cnt = j, cur = s[i].sat[j];
                }
            }
            cur = -1;
            for(int j = 0; j < 3; j++){
                if(j == cnt)continue;
                if(s[i].sat[j] > cur){
                    cnd = j, cur = s[i].sat[j];
                }
            }
            s[i].pri[0] = cnt, s[i].pri[1] = cnd;
            s[i].mad = s[i].sat[s[i].pri[0]] - s[i].sat[s[i].pri[1]];
            apar[s[i].pri[0]].push(s[i]);
            //cout << s[i].pri[0] << ' ' << s[i].pri[1] << " this is " << s[i].id  << " in " << s[i].pri[0];
        }
        //cout << endl;
        for(int i = 0; i < 3; i++){
            int sz = apar[i].size();
            for(int j = 0; j < sz - n / 2; j++){
                apar[apar[i].top().pri[1]].push(apar[i].top());
                //cout << apar[i].top().id << "from " << i << " is kicked to " << apar[i].top().pri[1];
                apar[i].pop();
            }
        }
        //cout << endl;
        ans = 0;
        for(int i = 0; i < 3; i++){
            //cout << "now is " << i << ':';
            int sszz = apar[i].size();
            for(int j = 0; j < sszz; j++){
                ans += apar[i].top().sat[i];
                //cout << apar[i].top().id << ' ';
                apar[i].pop();
            }
            //cout << endl;
        }
        cout << ans << endl;
    }
    return 0;
}