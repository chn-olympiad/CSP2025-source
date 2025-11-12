#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
struct aa{
    int id,zhi;
}num[N][4];
int ch[N];
int cnt[4];
int n,len,ans;
int p[N];
bool cmp(aa x,aa y){
    return x.zhi > y.zhi;
}
void sol(){
    cin >> n;
    cnt[1] = cnt[2] = cnt[3] = 0;
    ans = 0;
    for(int i = 1;i <= n;i++){
        cin >> num[i][1].zhi >> num[i][2].zhi >> num[i][3].zhi;
        num[i][1].id = 1,num[i][2].id = 2,num[i][3].id = 3;
        sort(num[i]+1,num[i]+1+3,cmp);
        cnt[num[i][1].id]++;
        ans += num[i][1].zhi;
    }
    if(cnt[1] <= n/2 && cnt[2] <= n/2 && cnt[3] <= n/2){
        cout << ans << '\n';
        return;
    }
    len = 0;
    for(int i = 1;i <= n;i++){
        if(cnt[num[i][1].id] > n/2){
            p[++len] = num[i][1].zhi-num[i][2].zhi;
        }
    }
    sort(p+1,p+1+len);
    int an = max(cnt[1],max(cnt[2],cnt[3]));
    for(int i = 1;i <= an-n/2;i++){
        ans -= p[i];
    }
    cout << ans << '\n';
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int _;
    cin >> _;
    while(_--){
        sol();
    }
}
