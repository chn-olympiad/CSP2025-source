//4.2
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,cnt,ans,c[505],v[505],nums[505];
char ch[505];

void dfs(int cs){
    if(cs > n){
        int num = 0,sum = 0;
        for(int i = 1;i <= n;i++){
            if(ch[i] == 0 || num >= c[i]){
                num++;
                continue;
            }
            sum++;
        }
        if(sum >= m){
            ans++;
        }
    }
    for(int i = 1;i <= n;i++){
        if(v[i] == 0){
            v[i] = 1;
            nums[cs] = i;
            dfs(cs+1);
            v[i] = 0;
        }
    }
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>ch[i];
        if(ch[i] == '1'){
            cnt++;
        }
    }
    for(int i = 1;i <= n;i++){
        cin>>c[i];
    }
    if(cnt == n){
        ans = 1;
        for(int i = 1;i <= n;i++){
            ans *= i;
        }
        cout<<ans;
        return 0;
    }
    cout<<ans;
    return 0;
}
