#include<bits/stdc++.h>
using namespace std;
struct node{
    int x, y, z;
}a[20005];
void s(node &a){
    if(a.x < a.y) swap(a.x, a.y);
    if(a.x < a.z) swap(a.x, a.z);
    if(a.y < a.z) swap(a.y, a.z);
}
bool cmp(node a, node b){
    s(a), s(b);
    if(a.x - a.y != b.x - b.y) return a.x - a.y > b.x - b.y;
    return a.y - a.z > b.y - b.z;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int cnt[5] = {}, s = 0;
        for(int i = 1;i <= n;i++)
            scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
        sort(a + 1, a + n + 1, cmp);
        for(int i = 1;i <= n;i++){
            int a1, a2, a3;
            if(a[i].x >= a[i].y && a[i].y >= a[i].z) a1 = 1, a2 = 2, a3 = 3;
            if(a[i].x >= a[i].z && a[i].z >= a[i].y) a1 = 1, a2 = 3, a3 = 2;
            if(a[i].y >= a[i].x && a[i].x >= a[i].z) a1 = 2, a2 = 1, a3 = 3;
            if(a[i].y >= a[i].z && a[i].z >= a[i].x) a1 = 2, a2 = 3, a3 = 1;
            if(a[i].z >= a[i].x && a[i].x >= a[i].y) a1 = 3, a2 = 1, a3 = 2;
            if(a[i].z >= a[i].y && a[i].y >= a[i].x) a1 = 3, a2 = 2, a3 = 1;
            int b1, b2, b3;
            if(a1 == 1) b1 = a[i].x;
            if(a1 == 2) b1 = a[i].y;
            if(a1 == 3) b1 = a[i].z;
            if(a2 == 1) b2 = a[i].x;
            if(a2 == 2) b2 = a[i].y;
            if(a2 == 3) b2 = a[i].z;
            if(a3 == 1) b3 = a[i].x;
            if(a3 == 2) b3 = a[i].y;
            if(a3 == 3) b3 = a[i].z;
            if(cnt[a1] < n / 2) s += b1, cnt[a1]++;
            else if(cnt[a2] < n / 2) s += b2, cnt[a2]++;
            else s += b3, cnt[a3]++;
        }
        printf("%d\n", s);
    }
    return 0;
}
