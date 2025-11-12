#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt;
int const N=500+10;
int c[N];
string a;
bool vis[N];
void dfs(int loser,int day,int winner){
    if(day==n+1){
        if(winner==m) cnt=(cnt+1)%998244353;
        return;
    }
    for(int i=1;i<=n;i++){//bian li ren
        if(vis[i]==0){
            vis[i]=1;//ren already ce le
            if(a[day]=='0'||loser>=c[i]){//test difficult or no patient
                dfs(loser+1,day+1,winner);
            }else{
                dfs(loser,day+1,winner+1);
            }
            vis[i]=0;
        }
    }

}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.in","w",stdout);
    cin>>n>>m;
    cin>>a;
    a="#"+a;
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    dfs(0,1,0);
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}


