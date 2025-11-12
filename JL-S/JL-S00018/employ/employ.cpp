#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;
int a[520];
int p[520];
int n,m;
int dfs(int x,int es,bool b[]){
    if(x>n)
        return es<=n-m;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(b[i]) continue;
        b[i]=true;
        if(a[x]==0||es>=p[i])
            ans+=dfs(x+1,es+1,b);
        else
            ans+=dfs(x+1,es,b);
        b[i]=false;
    }
    return ans;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    bool b[520];
    memset(b,0,sizeof(b));
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        char ch;
        cin>>ch;
        if(ch=='0')
            a[i]=0;
        else
            a[i]=1;
    }
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    int cnt=dfs(1,0,b);
    cout<<cnt<<endl;
    return 0;
}
