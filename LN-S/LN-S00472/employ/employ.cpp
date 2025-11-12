#include<bits/stdc++.h>
using namespace std;
int n, m;
string s;
int ans = 0;
const int N = 107;
bool st[N];
int c[N];
int a[N];
void dfs(int num, int cnt, int sum){
    if(num>n){
        if(sum>=m) ans++;
    }
    for(int i = 1; i <= n; i++){
        if(!st[i]){
            a[num] = i;
            st[i] = true;
            if(cnt>=c[i]){
                dfs(num+1,cnt+1,sum);
            }else{
                int nums = s[num-1]-'0';
                if(nums==0){
                    dfs(num+1,cnt+1,sum);
                }else{
                    dfs(num+1,cnt,sum+1);
                }
            }
            st[i]=false;
        }
    }
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >>n >> m;
    cin >> s;
    for(int i = 1; i <= n; i++) cin >> c[i];
    dfs(1,0,0);
    cout << ans;
    return 0;
}
