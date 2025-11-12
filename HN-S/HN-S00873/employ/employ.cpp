#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],c[505],s=1;
string b;

bool dfs(int x,int y){
    if (x<=y){
        return false;
    }
    return true;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>b;
    for(int i=0;i<n;i++){
        if(b[i]=='1'){
            a[i+1]=1;
        }
        cin>>c[i];
    }

    sort(c,c+n,dfs);
    for(int i=1;i<=m;i++){
        s*=n;
    }
    cout<<s;
    return 0;
}
