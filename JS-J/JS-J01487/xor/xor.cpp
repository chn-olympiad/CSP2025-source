#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[500005];
int ans;
bool flag = 1;

struct node{
    int l,r;
};

vector <node> ve;
node _time[500005];
int idx;
bool cmp(node a,node b){
    return a.r < b.r;
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
        if (a[i] == k) ans++;
        if (a[i] != 0 && a[i] != 1) flag = 0;
    }
    if (flag){
        if (k == 0){
            int cnt = 0;
            for (int i = 1;i <= n;i++){
                if (a[i] == 1) cnt++;
                else{
                    ans += cnt / 2;
                    cnt = 0;
                }
            }
            cout << ans + cnt / 2;
        }
        else cout << ans;
    }
    else{
        for (int i = 1;i <= n;i++){
            if (a[i] == k) continue;
            int tmp = a[i];
            int j;
            for (j = i + 1;j <= n;j++){
                if (a[j] == k) break;
                tmp ^= a[j];
                if (tmp == k) break;
            }
            if (tmp == k){
                //ve.push_back((node){i,j});
                _time[++idx] = (node){i,j};
            }
        }
        sort(_time + 1,_time + 1 + idx,cmp);
        int t = 0;
        for (int i = 1;i <= idx;i++){
            if(_time[i].l <= t) continue;
            ans++;
            t = _time[i].r;
        }
        cout << ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
