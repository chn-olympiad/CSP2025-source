#include<bits/stdc++.h>
using namespace std;
struct Info {
    int x,y;
} f1[100010],f2[100010],f3[100010];
int t,n,a[100010][5],ans,top1,top2,top3,cnt[100010];
bool cmp(Info x,Info y){
    return x.y > y.y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t; while (t--){
        cin >> n,ans = top1 = top2 = top3 = 0;
        for (int i = 1;i <= n;i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
        for (int i = 1;i <= n;i++){
            int x = max(a[i][1],max(a[i][2],a[i][3]));
            if (x == a[i][1]) f1[++top1].x = i,f1[top1].y = a[i][1];
            else if (x == a[i][2]) f2[++top2].x = i,f2[top2].y = a[i][2];
            else f3[++top3].x = i,f3[top3].y = a[i][3];
        }
        for (int i = 1;i <= top1;i++) ans += f1[i].y;
        for (int i = 1;i <= top2;i++) ans += f2[i].y;
        for (int i = 1;i <= top3;i++) ans += f3[i].y;
        if (top1 > n / 2){
            for (int i = 1;i <= top1;i++) cnt[i] = f1[i].y - max(a[f1[i].x][2],a[f1[i].x][3]);
            sort(cnt + 1,cnt + top1 + 1);
            for (int i = 1;i <= top1 - n / 2;i++) ans -= cnt[i];
        } else if (top2 > n / 2){
            for (int i = 1;i <= top2;i++) cnt[i] = f2[i].y - max(a[f2[i].x][1],a[f2[i].x][3]);
            sort(cnt + 1,cnt + top2 + 1);
            for (int i = 1;i <= top2 - n / 2;i++) ans -= cnt[i];
        } else if (top3 > n / 2){
            for (int i = 1;i <= top3;i++) cnt[i] = f3[i].y - max(a[f3[i].x][1],a[f3[i].x][2]);
            sort(cnt + 1,cnt + top3 + 1);
            for (int i = 1;i <= top3 - n / 2;i++) ans -= cnt[i];
        }
        cout << ans << endl;
    }
    return 0;
}
