#include<iostream>
#include<queue>
using namespace std;

const int MAXN=2e5+5;
int n,q;
string s[MAXN][2],t1,t2;

int bfs(){
    int ans=0;
    string x=t1;
    for(int i=1;i<=n;i++){
        int p=-1;
        for(int j=0;j+s[i][0].size()-1<x.size();j++)
            if(x.substr(j,s[i][0].size())==s[i][0]){
                p=j;
                break;
            }
        if(p==-1)continue;
        string nw=x.substr(0,p)+s[i][1]+x.substr(p+s[i][0].size());
        if(nw==t2)ans++;
    }
    return ans;
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>s[i][0]>>s[i][1];
    while(q--){
        cin>>t1>>t2;
        cout<<bfs()<<endl;
    }
    return 0;
}