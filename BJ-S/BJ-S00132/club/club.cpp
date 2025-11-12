#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int t, n, v[maxn][5], sum, flaga, flagb, flagc;
vector<int> a, b, c;
bool cmp(int x, int y){
    return v[x][4] > v[y][4];
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--){
        cin >> n;
        memset(v, 0, sizeof(v));
        a.clear();
        b.clear();
        c.clear();
        sum = flaga = flagb = flagc = 0;
        for(int i = 1; i <= n; i++){
            cin >> v[i][1] >> v[i][2] >> v[i][3];
            v[i][4] = max(max(v[i][1], v[i][2]), v[i][3]);
            if(v[i][4] == v[i][1]) a.push_back(i);
            else if(v[i][4] == v[i][2]) b.push_back(i);
            else c.push_back(i);
        }
        if(a.size() > n / 2){
            sort(a.begin(), a.end(), cmp);
            for(int i = 0; i < n / 2; i++){
                sum += v[a[i]][1];
            }
            for(int i = n / 2; i < a.size(); i++){
                if(v[a[i]][2] > v[a[i]][3]) b.push_back(a[i]);
                else c.push_back(a[i]);
            }
            flaga = 1;
        }
        if(b.size() > n / 2){
            sort(b.begin(), b.end(), cmp);
            for(int i = 0; i < n / 2; i++){
                sum += v[b[i]][2];
            }
            for(int i = n / 2; i < b.size(); i++){
                if(!flaga){
                    if(v[b[i]][1] > v[b[i]][3]) a.push_back(b[i]);
                    else c.push_back(b[i]);
                }else c.push_back(b[i]);
            }
            flagb = 1;
        }
        if(c.size() > n / 2){
            sort(c.begin(), c.end(), cmp);
            for(int i = 0; i < n / 2; i++){
                sum += v[c[i]][3];
            }
            for(int i = n / 2; i < c.size(); i++){
                if(!flaga && !flagb){
                    if(v[c[i]][1] > v[c[i]][2]) a.push_back(c[i]);
                    else b.push_back(c[i]);
                }else if(!flagb) b.push_back(c[i]);
                else if(!flaga) a.push_back(c[i]);
            }
            flagc = 1;
        }
        if((a.size() <= n / 2 || flaga) && (b.size() <= n / 2 || flagb) && (c.size() <= n / 2 || flagc)){
            if(!flaga){
                for(int i = 0; i < a.size(); i++) sum += v[a[i]][1];
                flaga = 1;
            }
            if(!flagb){
                for(int i = 0; i < b.size(); i++) sum += v[b[i]][2];
                flagb = 1;
            }
            if(!flagc){
                for(int i = 0; i < c.size(); i++) sum += v[c[i]][3];
                flagc = 1;
            }
            cout << sum <<'\n';
            continue;
        }
        if(a.size() > n / 2){
            sort(a.begin(), a.end(), cmp);
            for(int i = 0; i < n / 2; i++){
                sum += v[a[i]][1];
            }
            for(int i = n / 2; i < a.size(); i++){
                if(v[a[i]][2] > v[a[i]][3]) b.push_back(a[i]);
                else c.push_back(a[i]);
            }
            flaga = 1;
        }
        if(b.size() > n / 2){
            sort(b.begin(), b.end(), cmp);
            for(int i = 0; i < n / 2; i++){
                sum += v[b[i]][2];
            }
            for(int i = n / 2; i < b.size(); i++){
                if(!flaga){
                    if(v[b[i]][1] > v[b[i]][3]) a.push_back(b[i]);
                    else c.push_back(b[i]);
                }else c.push_back(b[i]);
            }
            flagb = 1;
        }
        if(c.size() > n / 2){
            sort(c.begin(), c.end(), cmp);
            for(int i = 0; i < n / 2; i++){
                sum += v[c[i]][3];
            }
            for(int i = n / 2; i < c.size(); i++){
                if(!flaga && !flagb){
                    if(v[c[i]][1] > v[c[i]][2]) a.push_back(c[i]);
                    else b.push_back(c[i]);
                }else if(!flagb) b.push_back(c[i]);
                else if(!flaga) a.push_back(c[i]);
            }
            flagc = 1;
        }
        if((a.size() <= n / 2 || flaga) && (b.size() <= n / 2 || flagb) && (c.size() <= n / 2 || flagc)){
            if(!flaga){
                for(int i = 0; i < a.size(); i++) sum += v[a[i]][1];
                flaga = 1;
            }
            if(!flagb){
                for(int i = 0; i < b.size(); i++) sum += v[b[i]][2];
                flagb = 1;
            }
            if(!flagc){
                for(int i = 0; i < c.size(); i++) sum += v[c[i]][3];
                flagc = 1;
            }
            cout << sum <<'\n';
            continue;
        }
        if(a.size() > n / 2){
            sort(a.begin(), a.end(), cmp);
            for(int i = 0; i < n / 2; i++){
                sum += v[a[i]][1];
            }
            for(int i = n / 2; i < a.size(); i++){
                if(v[a[i]][2] > v[a[i]][3]) b.push_back(a[i]);
                else c.push_back(a[i]);
            }
            flaga = 1;
        }
        if(b.size() > n / 2){
            sort(b.begin(), b.end(), cmp);
            for(int i = 0; i < n / 2; i++){
                sum += v[b[i]][2];
            }
            for(int i = n / 2; i < b.size(); i++){
                if(!flaga){
                    if(v[b[i]][1] > v[b[i]][3]) a.push_back(b[i]);
                    else c.push_back(b[i]);
                }else c.push_back(b[i]);
            }
            flagb = 1;
        }
        if(c.size() > n / 2){
            sort(c.begin(), c.end(), cmp);
            for(int i = 0; i < n / 2; i++){
                sum += v[c[i]][3];
            }
            for(int i = n / 2; i < c.size(); i++){
                if(!flaga && !flagb){
                    if(v[c[i]][1] > v[c[i]][2]) a.push_back(c[i]);
                    else b.push_back(c[i]);
                }else if(!flagb) b.push_back(c[i]);
                else if(!flaga) a.push_back(c[i]);
            }
            flagc = 1;
        }
        cout << sum << "\n";
    }
    return 0;
}