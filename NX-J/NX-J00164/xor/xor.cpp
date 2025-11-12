#include<bits/stdc++.h>
using namespace std;

int n,k,cnt = 0,ans = 0;
vector<int> a[500001];

void dfs(int p){
    if (p > n){
        ans = max(ans,cnt);
        return;
    }
    for (int i = p;i <= n;i++){
        if (a[p][i] == k){
            cnt++;
            dfs(i + 1);
            cnt--;
            break;
        }
    }
    dfs(p + 1);
}

int main(){
    for (int i = 1;i <= 500000;i++)
        a[i].push_back(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for (int i = 1;i <= n;i++){
        int x;
        scanf("%d",&x);
        for (int j = 1;j <= i;j++){
            if (j == i)
                a[j][i] = x;
            else
                a[j][i] = a[j][i - 1] ^ x;
        }
    }
    dfs(1);
    printf("%d",ans);
    return 0;
}
