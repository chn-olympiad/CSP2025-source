#include<bits/stdc++.h>
#define int long long
#define maxn ( 100000 +5)
using namespace std;
//吾日三省吾身：freopen删注释了乎？大样例测了乎？暴力打了乎？
//please open use UTF-8
int t,n,a[maxn][5],f[maxn][5];
int ans;
priority_queue<int>hope;
void dfs(int x,int s1,int s2,int s3,int sum){
    if(x==n+1){
        ans=max(ans,sum);
        //cout << sum << endl;
        return;
    }
    if(s1>=1)dfs(x+1,s1-1,s2,s3,sum+a[x][1]);
    if(s2>=1)dfs(x+1,s1,s2-1,s3,sum+a[x][2]);
    if(s3>=1)dfs(x+1,s1,s2,s3-1,sum+a[x][3]);
    if(s1<1 && s2<1 && s3<1){
        ans=max(ans,sum);
        return;
    }
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        bool flag=0;
        for(int i=1;i<=n;i++){
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            if(a[i][2]!=0 || a[i][3]!=0)flag=1;
            hope.push(a[i][1]);
        }
        if(!flag){
            for(int i=1;i<=n/2;i++){
                ans+=hope.top();
                hope.pop();
            }
            cout << ans << endl;
            ans=0;
            continue;
        }
        dfs(1,n/2,n/2,n/2,0);
        cout << ans << endl;
        ans=0;
    }
    return 0;
}