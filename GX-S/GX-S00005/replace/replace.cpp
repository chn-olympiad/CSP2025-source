#include<bits/stdc++.h>
using namespace std;
int n,m;
void fish(string x,string y){
    int cnt=0;
    for(int i=0;i<x.size();i++){
        if(x[i]!=y[i])cnt++;
    }
    cout<<cnt<<endl;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string x,y;
        cin>>x>>y;
    }
    for(int i=1;i<=m;i++){
        string x,y;
        cin>>x>>y;
        if(x.size()!=y.size())cout<<0<<endl;
        else fish(x,y);
    }
    return 0;
}
