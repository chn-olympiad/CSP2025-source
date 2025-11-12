#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t;
struct node{
    string x,y;
}s[200005];
queue<string> q;
map<string,bool> m;
int bfs(string s1,string s2){
    q.push(s1);
    m[s1]=1;
    int cnt=0;
    while(!q.empty()){
        string h=q.front();q.pop();
        if(h==s2){
            cnt++;
            continue;
        }
        for(int i=1;i<=n;i++){
            int k=s1.find(s[i].x);
            while(k!=-1){
                string o=h;
                int e=s[i].x.size();
                for(int j=k;j<=e+k-1;j++){
                    if(j-k<s[i].y.size())
                        o[j]=s[i].y[j-k];
                    else{
                        o.erase(j,1);
                    }
                }
                if(!m[o]||o==s2){
                    q.push(o);
                    m[o]=1;
                }
                string tmp=h+"111";
                tmp.erase(0,k+s[i].y.size());
                tmp=tmp.substr(tmp.size()-3);
                int v=tmp.find(s[i].x);
                if(v==-1)break;
                k+=v+1;
            }
        }
    }
    return cnt;
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>t;
    for(int i=1;i<=n;i++){
        cin>>s[i].x>>s[i].y;
    }
    for(int i=1;i<=t;i++){
        string u,v;
        cin>>u>>v;
        cout<<bfs(u,v)<<"\n";
    }
}//Ren5Jie4Di4Ling5%
