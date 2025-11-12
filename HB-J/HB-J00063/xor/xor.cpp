#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

int n, k, a[N], s[N], ans;
bool vis[N];
bool all01 = 1;

int main(){

    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    scanf("%d %d", &n, &k);
    if((k != 0) || (k != 1)){
        all01 = 0;
    }
    for(int i = 1; i <= n; i ++){
        scanf("%d", &a[i]);
        if((a[i] != 0) || (a[i] != 1)){
            all01 = 0;
        }
        s[i] = s[i - 1] ^ a[i];
    }
    if((n >= 1e4) && (all01 == 1)){
        if(k == 0){
            for(int i= 1; i <= n; i ++){
                if(a[i] == 0){
                    ans++;
                }else{
                    if((a[i - 1] == 1) && (vis[i - 1] == 0)){
                        ans++;
                        vis[i - 1] = vis[i] = 1;
                    }
                }
            }
        }else if(k == 1){
            for(int i= 1; i <= n; i ++){
                if(a[i] == 1){
                    ans++;
                }
            }
        }        
    }else{
        int last = 0;
        for(int i = 1; i <= n; i ++){
            for(int j = last + 1; j <= i; j ++){
                if((s[j - 1] ^ s[i]) == k){
                    ans++;
                    last = i;
                    break;
                }
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}