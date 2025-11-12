#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int a,b,c;
    cin>>a>>b>>c;
    int s[a+1][a+1];
    for(int i=1;i<=a;i++){
        s[i][i]=INT_MAX;
    }
    int n[b+1],m[b+1],w[b+1];
    for(int i=1;i<=b;i++){
        cin>>n[i]>>m[i]>>w[i];
        s[n[i]][m[i]]=min(s[n[i]][m[i]],w[i]);
        s[m[i]][n[i]]=min(s[m[i]][n[i]],w[i]);
    }
    int g[c+1][1+a],v[c+1]={0};
    for(int i=1;i<=c;i++){
        for(int j=0;j<=a;j++){
            cin>>g[i][j];
        }
    }
    for(int i=1;i<=c;i++){
        for(int j=0;j<=a;j++){
            cin>>g[i][j];
        }
    }
    for(int i=1;i<=b;i++){
        for(int j=1;j<=c;j++){
            s[n[i]][m[i]]=min(s[n[i]][m[i]],g[i][m[i]]+g[i][n[i]);
        }
    }
    long long ans=0;
    for(int i=1;i<=a;i++){
        ans+=s[i][1];
    }
    cout<<ans;
    return 0;
}
