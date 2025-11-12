#include <bits/stdc++.h>
using namespace std;
int n,m,z,a[505];
string s;
bool p[505];
void dfs(int depth,int t,int f){
    if (depth>n){
        if (t>=m) z++;
        return ;
    }
    for (int i=1;i<=n;i++){
        if (p[i]==0){
            p[i]=1;
            if (f>=a[i]) dfs(depth+1,t,f+1);
            else{
                if (s[depth]=='1') dfs(depth+1,t+1,f);
                else dfs(depth+1,t,f+1);
            }
            p[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    s=' '+s;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    dfs(1,0,0);
    cout<<z;
    return 0;
}
