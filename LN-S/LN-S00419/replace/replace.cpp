#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r;
    string s;
};
vector<node>a;
bool operator == (node a,node b){
    return a.l==b.l&&a.r==b.r&&a.s==b.s;
}
int n,q;
signed main(){
    freopen()
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        node la;
        string x,y;
        cin>>x>>y;
        for(int j=0;j<x.size();j++){
            if(x[j]=='b'){
                la.l=j,la.r=(int)(x.size())-j-1;
                break;
            }
        }
        la.s=y;
        a.push_back(la);
    }

    cout<<n;
}
