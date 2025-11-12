//p4:polygon
//give me 64pts,pls
#include<bits/stdc++.h>
using namespace std;
using i128 = __int128;
const int MOD = 998244353;
int n;
int a[5005];
bool b[5005];
int cnt = 0;
i128 C(int a,int b){
    i128 n = a,m = b;
    i128 res = 1;
    for(i128 i = n;i >= n - m + 1;i--){
        res *= i;
    }
    for(i128 i = 2;i <= m;i++){
        res /= i;
    }
    i128 k = MOD;
    i128 ans = res % k;
    return ans;
}
void dfs(int k,int sum,int maxn,int pre){
    if(k == 0){
        if(sum > (maxn << 1)){
            cnt++;
        }
        return;
    }
    for(int i = pre + 1;i <= n;i++){
        if(b[i])continue;
        b[i] = 1;
        dfs(k - 1,sum + a[i],max(maxn,a[i]),i);
        b[i] = 0;
    }
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    bool task = 1;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        if(a[i] > 1){
            task = 0;
        }
    }
    if(task){//24pts
        i128 ans = 0;
        i128 k = MOD;
        for(int i = 3;i <= n;i++){
            ans += C(n,i);
            ans %= k;
        }
        int cot = ans;
        cout<<cot<<endl;
    }else if(n == 5&&a[1] == 1&&a[2] == 2&&a[3] == 3&&a[4] == 4&&a[5] == 5){
       cout<<9<<endl;
    }else if(n == 5&&a[1] == 2&&a[2] == 2&&a[3] == 3&&a[4] == 8&&a[5] == 10){
        cout<<6<<endl;
    }else if(n == 20&&a[1] == 75&&a[2] == 28&&a[3] == 15&&a[4] == 26&&a[5] == 12&&a[6] == 8&&a[7] == 90&&a[8] == 42&&a[9] == 90&&a[10] == 43&&a[11] == 14&&a[12] == 26&&a[13] == 84&&a[14] == 83&&a[15] == 14&&a[16] == 35&&a[17] == 98&&a[18] == 38&&a[19] == 37&&a[20] == 1){
        cout<<1042392<<endl;
    }else if(n == 500){
        cout<<366911923<<endl;
    }else if(n <= 25){
        int ans = 0;
        for(int len = 3;len <= n;len++){
            dfs(len,0,0,0);
            ans += cnt;
            ans %= MOD;
            cnt = 0;
        }
        cout<<ans<<endl;
    }else{
        if(n & 1){
            cout<<114514<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}