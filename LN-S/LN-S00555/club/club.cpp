#include <bits/stdc++.h>

using namespace std;
const int INT = 1e5+5;
inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x<<3)+(x<<1)+ch-'0';
        ch = getchar();
    }
    return x*f;
}
struct node{
    int a,b,c;
}s[INT];
int n,dp[INT][5],maxn=-1e9;
void bfs(int i, int ar,int br, int cr, int sum){
    if(i>n)maxn = max(maxn, sum);
    else{
    if(ar + 1 <= n/2)bfs(i+1,ar+1,br,cr,sum+s[i].a);
    if(br + 1 <= n/2)bfs(i+1,ar,br+1,cr,sum+s[i].b);
    if(cr + 1 <= n/2)bfs(i+1,ar,br,cr+1,sum+s[i].c);
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T = read();
    while(T--){
        n = read();
        for(int i = 1; i <= n; i++)
            s[i].a=read(), s[i].b=read(), s[i].c=read();
        bfs(1,0,0,0,0);
        /*
        for(int i = 1; i <= n; i++){
            for(int j = n/2; j >= 0; j--){
                dp[j][1] = max(dp[j][1], dp[j-1][1]+s[i].a);
                dp[j][2] = max(dp[j][2], dp[j-1][2]+s[i].b);
                dp[j][3] = max(dp[j][3], dp[j-1][3]+s[i].c);
            }
        }
        for(int i = 0; i <= n/2; i++){
            for(int j = 0; j <= 3; j++)cout << dp[i][j] << " ";
            cout << endl;
        }
        cout << dp[0][1]+dp[0][2]+dp[0][3] << endl;*/
        cout << maxn << endl;
        maxn = -1e9;
    }
    return 0;
}
