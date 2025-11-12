#include <bits/stdc++.h>
using namespace std;
int n, m, l;
pair<int, int> a[100000];
pair<int, int> cnt[100000];
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int j = 1; j <= m; j++){
        if(j % 2 == 1){
            for(int i = 1; i <= n; i++)
                cnt[++l] = make_pair(j, i);
        }else{
            for(int i = n; i; i--)
                cnt[++l] = make_pair(j, i);
        }
    }
    for(int i = 1; i <= n * m; i++){
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a + 1, a + n * m + 1);
    reverse(a + 1, a + n * m + 1);
    for(int i = 1; i <= n * m; i++)
        if(a[i].second == 1)
            printf("%d %d\n", cnt[i].first, cnt[i].second);
    return 0;
}
