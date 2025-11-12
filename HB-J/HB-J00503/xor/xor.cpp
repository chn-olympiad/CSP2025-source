#include<bits/stdc++.h>
using namespace std;
int a,ans;
int s[500010];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin  >> n >> k;
    for(int i  = 1;i <= n;i ++){
        cin  >> a;
        s[i] = s[i-1]^a;
    }
    for(int i = 0;i < n;i ++){
        for(int j = i+1;j <= n;j ++){
            if((s[i]^s[j]) == k){
                i = j;
                ans ++;
                continue;
            }
        }
    }
    cout << ans;
    return 0;
}
