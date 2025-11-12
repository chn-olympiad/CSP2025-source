#include<iostream>
#include<cstdio>
using namespace std;
struct inter{
    bool f=false;
    int x[4];
}a[100005];
int t,n;
int maxn;
int sum[4];
void dfs(int w,int num){
    if(w>n){
        maxn=max(maxn,num);
        return;
    }
    for(int i=1;i<=n;i++){
        if(a[i].f) continue;
        a[i].f=true;
        for(int k=1;k<=3;k++){
            if(sum[k]>=n/2) continue;
            else{
                sum[k]++;
                dfs(w+1,num+a[i].x[k]);
                sum[k]--;
            }
        }
        a[i].f=false;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int o=1;o<=t;o++){
        cin>>n;
        maxn=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++) cin>>a[i].x[j];
        }
        dfs(1,0);
        cout<<maxn<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
