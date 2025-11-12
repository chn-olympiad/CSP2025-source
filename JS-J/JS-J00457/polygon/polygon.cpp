#include<bits/stdc++.h>
using namespace std;
const int N = 5005,MOD = 998244353;
int n,a[N],sum,maxn,ans;
pair<int,int> b[N];
bool flag;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    if(n == 3){
        sum = a[1] + a[2] + a[3];
        maxn = max(maxn,max(a[1],max(a[2],a[3])));
        if(sum > 2 * maxn) ans = 1 % MOD;
    }
    else if(n < 20){
        for(int len = 3;len <= n;len++){
            for(int i = 0;i < len;i++) b[i].first = b[i].second = 0;
            sum = 0,maxn = 0;
            for(int i = 0;i < len;i++)
                for(int j = 1;j <= n;j++){
                    flag = false;
                    for(int k = 0;k < i;k++){
                        if(b[i].second == j){
                            flag = true;
                            break;
                        }
                    }
                    if(flag) continue;
                    b[i] = {a[j],j};
                }
            for(int i = 0;i < len;i++){
                sum += b[i].first;
                maxn = max(maxn,b[i].first);
            }

        }
    }
    cout<<ans;
    return 0;
}
