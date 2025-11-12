#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][4];
vector<int> g[3];
vector<int> gcc;
void solve(){
     int n;cin>>n;
     for(int i=1;i<=n;i++){
         for(int j=0;j<3;j++){
             cin>>a[i][j];
         }
     }
     for(int i=1;i<=n;i++){
        int maxx=a[i][0],id=0;
        for(int j=0;j<3;j++){
            if(a[i][j]>maxx){
               maxx=a[i][j];
               id=j;
            }
        }
        g[id].push_back(i);
        a[i][3]=maxx;
     }
     int sum=0;
     for(int i=1;i<=n;i++){
        sum+=a[i][3];
     }
     for(int i=0;i<3;i++){
         if(g[i].size()<=n/2) continue;
         for(int j=0;j<g[i].size();j++){
             int maxx=-1;
             for(int k=0;k<3;k++){
                 if(a[g[i][j]][k]==a[g[i][j]][3]){
                    continue;
                 }
                 if(a[g[i][j]][k]>maxx){
                    maxx=a[g[i][j]][k];
                 }

             }
             cout<<g[i][j]<<" ";
             cout<<maxx<<" ";
             gcc.push_back(a[g[i][j]][3]-maxx);
         }
         sort(gcc.begin(),gcc.end());
         for(int j=1;j<=gcc.size()-n/2;j++){
             sum-=gcc[j-1];
         }
         gcc.clear();
     }
     cout<<sum<<"\n";
     for(int i=0;i<3;i++){
        g[i].clear();
     }
}

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
