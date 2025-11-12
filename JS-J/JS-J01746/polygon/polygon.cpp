#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010],vis[5010];
unsigned long long ans=0;
void dfs(int u,int ma,int k,int az,int l){
    if(u>k){
        if(az>2*ma){
            ans++;
        }
        return;
    }
    for(int i=l;i<n;i++){
        if(!vis[i]){
            int m=ma;
            ma=max(ma,a[i]);
            az+=a[i];
            vis[i]=1;
            dfs(u+1,ma,k,az,i);
            vis[i]=0;
            az-=a[i];
            ma=m;
        }
    }

}
int main(){
    ifstream in("polygon.in");
    ofstream out("polygon.out");
    in>>n;
    for(int i=0;i<n;i++){
            in>>a[i];

    }
    for(int i=3;i<=n;i++){
        dfs(1,0,i,0,0);
    }
    out<<(ans%998244353);
    return 0;
}
