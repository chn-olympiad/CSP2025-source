#include <bits/stdc++.h>
using namespace std;
int n, k, a[500050], sum[500050], tar[500050], ans, lst = -1;
vector<int> q[1050000];
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d %d", &n, &k);
    q[0].push_back(0);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d", a + i);
        sum[i] = sum[i - 1] ^ a[i];
        q[sum[i]].push_back(i);
        tar[i] = k ^ sum[i];
    }
    for(int i = 1 ; i <= n ; ++i){
        int pos1 = lower_bound(q[tar[i]].begin(), q[tar[i]].end(), i) - q[tar[i]].begin() - 1;
        int pos2 = lower_bound(q[tar[i]].begin(), q[tar[i]].end(), lst) - q[tar[i]].begin();
        if(pos1 < 0 || pos1 > q[tar[i]].size() || pos1 < pos2) continue;
        ans++;
        lst = i;
    }
    printf("%d\n", ans);
    fclose(stdin);
    fclose(stdout);
}
