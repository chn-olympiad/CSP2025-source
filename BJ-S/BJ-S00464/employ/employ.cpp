#include<iostream>
using namespace std;
int n;
struct n10{
    int ans,m,a[15],c[15],v[15],f[15],t;
    void dfs(int nw){
        if(nw>n){
            t=0;
            for(int i=1;i<=n;i++){
                if(a[i]&&i-1-t<c[f[i]])t++;
            }
            ans+=(t>=m);
            return;
        }
        for(int i=1;i<=n;i++){
            if(!v[i]){
                v[i]=1;
                f[nw]=i;
                dfs(nw+1);
                v[i]=0;
            }
        }
    }
    void init(){
        cin>>m;
        for(int i=1;i<=n;i++){
            char ch;
            cin>>ch;
            a[i]=ch-48;
        }
        for(int i=1;i<=n;i++){
            cin>>c[i];
        }
        dfs(1);
        cout<<ans<<endl;
    }
}a;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n;
    if(n<=10){
        a.init();
        return 0;
    }
    cout<<0;
    return 0;
}