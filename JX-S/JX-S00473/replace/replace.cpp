#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
string t[N][3];
string a[N][3];
bool zc(string x,string y){
     if(x.size()>y.size()){
        return false;
     }
     if(x==y) return true;
     for(int j=0;j<y.size();j++){
         if(x[0]!=y[j]){
            continue;
         }
         if(j+x.size()>y.size()){
            continue;
         }
        for(int k=0;k<x.size();k++){
            if(x[k]!=y[k+j]){
                break;
            }
        }
        return true;
     }
     return false;
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>t[i][1]>>t[i][2];
    }
    for(int i=1;i<=m;i++){
        cin>>a[i][1]>>a[i][2];
        string df[3];
        if(a[i][1].size()!=a[i][2].size()){
           cout<<0;
        }else{
           int ans=0;
           int l=0,r=a[i][i].size()-1;
           for(int j=0;j<=a[i][1].size()-1;j++){
               if(a[i][1][j]!=a[i][2][j]){
                  l=j;
                  for(int k=a[i][1].size()-1;k>=0;k--){
                      if(a[i][1][j]!=a[i][2][j]){
                         r=k;
                         break;
                      }
                  }
                  break;
               }
           }
           for(int j=0;l<=r;l++,j++){
               char c=a[i][1][l];
               df[1]+=c;
               char d=a[i][2][l];
               df[2]+=d;
           }
           for(int j=1;j<=n;j++){
               if(zc(df[1],t[j][1])&&zc(df[2],t[j][2])){
                  ans++;
               }
           }
           cout<<ans<<'\n';
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
