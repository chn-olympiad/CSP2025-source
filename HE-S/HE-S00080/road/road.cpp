#include<bits/stdc++.h>
using namespace std;
struct Node{
    int zd;
    int ans;
    int yn;
};
struct Nodee{
    int zdd;
    int anss;
    int num;
};
int n,m,z;
vector<Node> a[10100];
int c[10200];
int minn=INT_MAX;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>z;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        Node k;
        k.zd=v;
        k.ans=w;
        k.yn=0;
        a[u].push_back(k);
        k.zd=u;
        a[v].push_back(k);
    }
    for(int i=1;i<=z;i++){
        int w;
        cin>>w;
        c[n+i]=w;
        for(int j=0;j<n;j++){
            cin>>w;
            Node k;
            k.zd=j;
            k.ans=w;
            k.yn=0;
            a[n+i].push_back(k);
            k.zd=n+i;
            a[j].push_back(k);
        }
    }
    queue<Nodee> q;
    for(int i=0;i<a[1].size();i++){
        Nodee k;
        k.zdd=a[1][i].zd;
        k.anss=a[1][i].ans;
        k.num=1;
        if(a[1][i].zd>n){
            k.anss+=c[a[1][i].zd];
        }
        a[1][i].yn=1;
        a[i][1].yn=1;
        q.push(k);
    }
    while(!q.empty()){
        int qd=q.front().zdd;
        int sum=q.front().anss;
        int numm=q.front().num;
        q.pop();
        for(int i=0;i<a[qd].size();i++){
            if(a[qd][i].yn==0){
                Nodee k;
                k.zdd=a[qd][i].zd;
                k.anss=sum+a[qd][i].ans;
                k.num=numm+1;
                if(a[qd][i].zd>n){
                    k.anss+=c[a[qd][i].zd];
                }
                a[qd][i].yn=1;
                a[i][qd].yn=1;
                q.push(k);
            }
        }
        if(numm==n-1){
            minn=min(minn,sum);
        }
    }
    cout<<minn+1;
    return 0;
}
