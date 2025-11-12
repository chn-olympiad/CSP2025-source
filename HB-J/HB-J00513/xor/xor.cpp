#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],s[500005],cnt[500005];
bool flag = true;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        if(i == 1) s[i] = a[i];
        else s[i] = s[i - 1] ^ a[i];
        if(a[i] != 1) flag = false;
    }
    if(k == 0 && flag){
        printf("%d",n / 2);
        return 0;
    }
    for(int start = 1;start <= n;start++){
        for(int i = start;i <= n;i++){
            for(int j = i;j <= n;j++){
                if((s[i - 1] | s[j]) == k){
                    cnt[start]++;
                    i = j + 1;
                    j = j + 1;
                }
            }
        }
    }
    int maxn = 0;
    for(int i = 1;i <= n;i++){
        maxn = max(maxn,cnt[i]);
    }
    printf("%d",maxn);
}
