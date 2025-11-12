#include<bits/stdc++.h>
#define MAXN 505
using namespace std;
int a,m,n;
bool v[MAXN];
int c[MAXN];
string s;
void dfs(int x,int y,int z){
    if(x>n){
        if(y>=m)a=(a+1)%998244353;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!v[i]){
            v[i]=1;
            if(z>=c[i]||s[x-1]=='0')dfs(x+1,y,z+1);
            else dfs(x+1,y+1,z);
            v[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin),freopen("employ.out","w",stdout),cin>>n>>m>>s;
    for(int i=1;i<=n;i++)cin>>c[i];
    dfs(1,0,0),cout<<a;
    return 0;
}