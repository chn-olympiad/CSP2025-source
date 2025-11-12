#include<bits/stdc++.h>
using namespace std;
int t,n,ans,cnt[4],p[100005];
struct d{
    int num,department;
}a[100005][4];
bool cmp(d a,d b){
    return a.num > b.num;
}
void dfs(int x,int sum){
    if(x > n){
        ans = max(ans,sum);
        //for(int i = 1;i <= n;i++) cout << p[i] << " ";
        //cout << "\n";
        return;
    }
    for(int i = 1;i <= 3;i++){
        //cout << a[x][i].department << " ";
        if(cnt[a[x][i].department] + 1 > n / 2) continue;
        cnt[a[x][i].department]++;
        p[x] = a[x][i].num;
        dfs(x + 1,sum + a[x][i].num);
        cnt[a[x][i].department]--;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--){
        memset(&a,0,sizeof(a));
        cin >> n;
        ans = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= 3;j++){
                cin >> a[i][j].num;
                a[i][j].department = j;
            }
            sort(a[i] + 1,a[i] + n + 1,cmp);
        }
        dfs(1,0);
        cout << ans << "\n";//
    }
    return 0;
}
