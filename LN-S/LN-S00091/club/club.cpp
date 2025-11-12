#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int maxn;
int m;
int x[100010];
int y[100010];
int z[100010];
void dfs(int k,int ed,int a1,int b1,int c1,int a2,int b2,int c2){
    if(k>ed){
        if(a1+b1+c1>maxn){
            maxn=a1+b1+c1;
            return;
        }
    }
    if(a2<m){
        dfs(k+1,ed,a1+x[k],b1,c1,a2+1,b2,c2);
    }
    if(b2<m){
        dfs(k+1,ed,a1,b1+y[k],c1,a2,b2+1,c2);
    }
    if(c2<m){
        dfs(k+1,ed,a1,b1,c1+z[k],a2,b2,c2+1);
    }
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
        maxn=0;
        cin >> n;
        m=n/2;
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        memset(z,0,sizeof(z));
        for(int i=1;i<=n;i++){
            cin >> x[i];
            cin >> y[i];
            cin >> z[i];
        }
        dfs(1,n,0,0,0,0,0,0);
        cout << maxn << endl;
    }
    return 0;
}
