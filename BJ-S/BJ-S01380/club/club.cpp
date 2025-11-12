#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+9;
int n,sum;
int a[maxn][5];
int r[4];
inline int read(){
    int x=0;
    char ch = getchar();
    while(ch>='0'&&ch<='9'){
        x = x*10+ch-'0';
        ch = getchar();
    }
    return x;
}
void dfs(int k,int suma){

    if(suma + a[n][4]-a[k-1][4]<sum)return;
    if(k>n){
        sum = max(sum,suma);
        return;
    }
    else{
        for(int i=1;i<=3;i++){
            if(r[i]<n/2){
                r[i]++;
                dfs(k+1,suma+a[k][i]);
                r[i]--;
            }
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    t = read();
    while(t--){
        memset(r,0,sizeof(r));
        memset(a,0,sizeof(a));
        sum = 0;
        n = read();
        for(int i=1;i<=n;i++){
            a[i][1] = read();
            a[i][2] = read();
            a[i][3] = read();
            for(int j=1;j<=3;j++)a[i][4] = max(a[i][j],a[i][4]);
            a[i][4] += a[i-1][4];
        }
        dfs(1,0);
        cout << sum<<endl;
    }
    return 0;
}
