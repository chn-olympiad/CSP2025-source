#include<bits/stdc++.h>
using namespace std;
bool cmp(int a1,int b1){
    if(a1<=b1){
        return 1;
    }
    return 0;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int w[10000000],w1[10000000];
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v>>w[i];
    }
    int q=1;
    for(int i=1;i<=k;i++){
        int c;
        cin>>c;
        for(int j=1;j<=n;j++){
            int c1;
            cin>>c1;
            w1[q]=c1+c;
            q++;
        }
    }
    sort(w+1,w+m+1);
    sort(w1+1,w1+q);
    int cnt=0;
    for(int i=1;i<=m/2;i++){
        cnt+=w1[i]+w[i];
    }
    cout<<cnt;
    return 0;
}