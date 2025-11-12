#include <bits/stdc++.h>
using namespace std;

typedef struct{
    int l,r;
} car;

const int N = 500005;
int n,k;
int a[N], s[N];
vector<car> vec;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d %d",&n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        s[i] = s[i-1] ^ a[i];
    if (n <= 1005){
        for (int i = 1; i <= n; i++){
            for (int j = i; j <= n; j++){
                if ((s[i-1] ^ s[j]) == k)
                    vec.push_back({i,j});
            }
        }
        int ans = 0, lastr = 0;
        for (auto it : vec){
            if (it.l > lastr)
                ans++, lastr = it.r;
            if (it.r < lastr)
                lastr = it.r;
        }
        printf("%d",ans);
    }
    else{
        if (k == 1){
            int ans = 0;
            for (int i = 1; i <= n; i++){
                if (a[i] == 1) ans++;
            }
            printf("%d",ans);
        }
        else{
            int ans = 0;
            for (int i = 1; i <= n; ){
                if (a[i] == 0) ans++, i++;
                else{
                    int sta = i;
                    while (i <= n && a[i]) i++;
                    ans += (i-sta) / 2;
                }
            }
            printf("%d",ans);
        }
    }
    /*for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            int res = 0;
            for (int p = i; p <= j; p++) res ^= a[p];
            printf("%d\n",res == (s[i-1] ^ s[j]));
        }
    }*/

    return 0;
}

