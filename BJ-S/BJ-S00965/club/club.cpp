#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 100005;
struct Node{
    int x[4];
}a[MAXN];
bool cmp1(Node x, Node y){
    if(x.x[1] != y.x[1])return x.x[1] < y.x[1];
    if(x.x[2] != y.x[2])return x.x[2] < y.x[2];
    return x.x[3] < y.x[3];
}
bool cmp2(Node x, Node y){
    if(x.x[1] != y.x[1])return x.x[1] != y.x[1];
    if(x.x[3] != y.x[3])return x.x[3] < y.x[3];
    return x.x[2] < y.x[2];
}
bool cmp3(Node x, Node y){
    if(x.x[2] != y.x[2])return x.x[2] < y.x[2];
    if(x.x[1] != y.x[1])return x.x[1] < y.x[1];
    return x.x[3] < y.x[3];
}
bool cmp4(Node x, Node y){
    if(x.x[2] != y.x[2])return x.x[2] < y.x[2];
    if(x.x[3] != y.x[3])return x.x[3] < y.x[3];
    return x.x[1] < y.x[1];
}
bool cmp5(Node x, Node y){
    if(x.x[3] != y.x[3])return x.x[3] < y.x[3];
    if(x.x[1] != y.x[1])return x.x[1] < y.x[1];
    return x.x[2] < y.x[2];
}
bool cmp6(Node x, Node y){
    if(x.x[3] != y.x[3])return x.x[3] < y.x[3];
    if(x.x[2] != y.x[2])return x.x[2] < y.x[2];
    return x.x[1] < y.x[1];
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t --){
        int n, ans1, ans2, ans3, ans4, ans5, ans6;
        cin >> n;
        for(int i = 1; i <= n; i ++){
            cin >> a[i].x[1] >> a[i].x[2] >> a[i].x[3];
        }
        ans1 = ans2 = ans3 = ans4 = ans5 = ans6 = 0;
        int cur = 1;
        sort(a + 1, a + 1 + n, cmp1);
        for(int i = 1; i <= 3; i ++){
            for(int j = 1; j <= n / 2 && cur <= n; j ++){
                ans1 += a[cur].x[i];
                cur ++;
            }
        }
        cur = 1;
        sort(a + 1, a + 1 + n, cmp2);
        for(int i = 1; i <= 3; i ++){
            for(int j = 1; j <= n / 2 && cur <= n; j ++){
                ans2 += a[cur].x[i];
                cur ++;
            }
        }
        cur = 1;
        sort(a + 1, a + 1 + n, cmp3);
        for(int i = 1; i <= 3; i ++){
            for(int j = 1; j <= n / 2 && cur <= n; j ++){
                ans3 += a[cur].x[i];
                cur ++;
            }
        }
        cur = 1;
        sort(a + 1, a + 1 + n, cmp4);
        for(int i = 1; i <= 3; i ++){
            for(int j = 1; j <= n / 2 && cur <= n; j ++){
                ans4 += a[cur].x[i];
                cur ++;
            }
        }
        cur = 1;
        sort(a + 1, a + 1 + n, cmp5);
        for(int i = 1; i <= 3; i ++){
            for(int j = 1; j <= n / 2 && cur <= n; j ++){
                ans5 += a[cur].x[i];
                cur ++;
            }
        }
        cur = 1;
        sort(a + 1, a + 1 + n, cmp6);
        for(int i = 1; i <= 3; i ++){
            for(int j = 1; j <= n / 2 && cur <= n; j ++){
                ans6 += a[cur].x[i];
                cur ++;
            }
        }
        cout << max({ans1, ans2, ans3, ans4, ans5, ans6}) << "\n";
    }
    return 0;
}