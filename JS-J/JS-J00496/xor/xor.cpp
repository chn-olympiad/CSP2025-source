#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
int n,k,a[N],b[N][N],c[N][N];
bool r[N][N];

int sum(int l,int r){
    int sm = a[l++];
    while(l<=r){
        sm ^= a[l++];
    }
    return sm;
}

int dfs(int x,int y,int curr){
    if(b[x][y]!=k){
        return curr;
    }
    if(r[x][y]){
        return c[x][y];
    }
    curr++;
    r[x][y] = true;
    for(int i = y+1;i < n;i++){
        for(int j = i;j < n;j++){
            c[x][y] = max(c[x][y],dfs(i,j,curr));
        }
    }
    if(y==n-1){
        return curr;
    }
    return c[x][y];
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0;i < n;i++){
        for(int j = i;j < n;j++){
            b[i][j] = sum(i,j);
        }
    }
    int ans = 0;
    for(int i = 0;i < n;i++){
        for(int j = i;j < n;j++){
            ans = max(ans,dfs(i,j,0));
        }
    }
    printf("%d",ans);
    return 0;
}
