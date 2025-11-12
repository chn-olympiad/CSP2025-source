#include <bits/stdc++.h>
#define int long long
using namespace std;
int read();
void write(int x);
int n,a[5005],dp[5005][5005],s[5005];
bool cmp(int x,int y);
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        dp[i][i]=0;
        dp[i][i+1]=0;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j+i<=n;j++){

            dp[j][j+i]=dp[j][j+i-1]*2+dp[j+1][j+i]-dp[j+1][j+i-1];
            int t=s[j+i]-s[j-1];

            if(i==2&&t>(2*a[j])){
                dp[j][j+i]++;

            }
        }
    }

    write(dp[1][n]);
    return 0;
}
int read(){
    int x,y=1;char c;
    while((c=getchar())>'9'||c<'0') if(c=='-') y=-1;
    x=(c^48);
    while ((c=getchar())>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48);
    return x*y;
}
void write(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
bool cmp(int x,int y){
    return x>y;
}
