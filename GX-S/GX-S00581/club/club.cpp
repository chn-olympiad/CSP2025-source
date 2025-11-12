#include<iostream>
using namespace std;
int a[100086][3],cnt,maxn,n,c[3];
void dfs(int pos){
    if(pos == n){
        if(cnt > maxn)maxn = cnt;
        return;
    }for(int i = 0;i < 3;i++){
        if(c[i] < n / 2){
            cnt += a[pos][i];
            c[i]++;
            dfs(pos + 1);
            cnt -= a[pos][i];
            c[i]--;
        }
    }
}int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < 3;j++){
                cin>>a[i][j];
            }
        }dfs(0);
        cout<<maxn<<'\n';
        maxn = 0;
        cnt = 0;
    }return 0;
}
