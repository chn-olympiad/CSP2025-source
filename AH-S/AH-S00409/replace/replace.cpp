/*
*/
#include<bits/stdc++.h>
#define N 200005
using namespace std;
struct replace{
    string x,y;
}a[N];
int n,q;
string u,v;
int solve(string u,string v){
    int ans=0;
    string tmp=u;
    for(int i=1;i<=n;i++){
        string b=u;
        int t=u.find(a[i].x);
        int len=a[i].x.size();
        if(t==-1) continue;
        u.erase(t,len);
        u.insert(t,a[i].y);
        if(u==v) ans++,u=tmp;
        else u=b;
    }
    return ans;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    for(int i=1;i<=q;i++){
        cin>>u>>v;
        cout<<solve(u,v)<<"\n";
    }
    return 0;
}
