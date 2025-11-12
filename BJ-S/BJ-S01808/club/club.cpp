#include<iostream>
using namespace std;
int a[100005][4];
int ans,cnt,p[4],n;
void dfs(int x){
    if(x>n){
        if(ans<cnt){
            ans=cnt;
        }
        return ;
    }
    for(int i=1;i<=3;i++){
        if(p[i]<=n/2-1){
            p[i]++;
            cnt+=a[x][i];
            dfs(x+1);
            p[i]--;
            cnt-=a[x][i];
        }
        dfs(x+1);
    }
    return ;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
    }
    dfs(1);
    cout<<ans<<endl;
    ans=0;
    p[1]=0;
    p[2]=0;
    p[3]=0;
    cnt=0;
    }
    return 0;
}
