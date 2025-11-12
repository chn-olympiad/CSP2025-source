#include<bits/stdc++.h>
using namespace std;
int n,m;
map<string,string>mp;
const int N=4e6+5;
int t[27][N];
int ende[N];
vector<int>to[N];
int idx=0;
stack<int>st;
void add(string a){
    int x=0;
    for(int i=0;i<a.size();i++){
        int tt=a[i]-'a';
        if(t[tt][x]==0){
            t[tt][x]=++idx;
        }
        x=t[tt][x];
    }
    ende[x]++;
    to[x].push_back(a.size());
}
int fail[N];
void bfs(){
    queue<int>q;
    for(int i=0;i<27;i++){
        if(t[i][0]){
            q.push(t[i][0]);
        }
    }
    while(!q.empty()){
        int u=q.front();
        for(int i=0;i<27;i++){
            if(t[i][u]){
                fail[t[i][u]]=t[i][fail[u]];
                q.push(t[i][u]);
                ende[u]+=ende[fail[u]];
            }else{
                t[i][u]=t[i][fail[u]];
            }
        }
    }
}
int fin(string a,string b){
    int x=0;
    int ans=0;
    for(int i=0;i<a.size();i++){
        int xx=a[i]='a';
        if(ende[x]){
            bool fl=1;
            for(int j=0;j<to[x].size();j++){
                string ch="";
                for(int k=i-to[i][j];k<i;k++){
                    ch+=a[k];
                }
                string cp=mp[ch];
                for(int uu=0;uu<a.size();uu++){
                    char fk=a[i];
                    if(uu>=i-to[i][j]&&uu<i){
                        fk=cp[uu-to[i][j]];
                    }
                    if(fk!=b[i])fl=0;
                }
            }
            if(fl)ans++;
        }
        x=t[xx][x];
    }
    return ans;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string a,b;
        cin>>a>>b;
        mp[a]=b;
        add(a);
    }
    bfs();
    for(int i=1;i<=m;i++){
        string a,b;
        cin>>a>>b;
        cout<<0<<endl;
    }

    return 0;
}