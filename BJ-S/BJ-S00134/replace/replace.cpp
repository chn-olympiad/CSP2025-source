#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e6+5,Q=2e5+5;int n,q;string s[Q][2];string t0,t1;
//const ll B1=131,P1=1e9+7;
//const ll B1=101,P2=1e9+9;
//struct Hash{
//};
struct Izayoi_Sakuya{
    int nxt[N][26],tot,fail[N],dep[N];vector<int>val[2][N];
    void ins(int type,string s,int id){
        int p=0,len=s.length();
        for(int i=0;i<len;i++){
            int c=s[i]-'a';
            if(!nxt[p][c])nxt[p][c]=++tot,dep[nxt[p][c]]=dep[p]+1;
            p=nxt[p][c];
        }
        val[type][p].push_back(id);
    }
    void init(){
        queue<int>q;
        for(int i=0;i<26;i++){if(nxt[0][i]){/*g[0].push_back(nxt[0][i]);*/q.push(nxt[0][i]);}}
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int i=0;i<26;i++){
                if(nxt[u][i]){
                    fail[nxt[u][i]]=nxt[fail[u]][i];
                    /*g[nxt[fail[u]][i]].push_back(nxt[u][i]);*/
                    q.push(nxt[u][i]);
                }
                else{
                    nxt[u][i]=nxt[fail[u]][i];
                }
            }
        }
    }
//    void dfs(int u){
//        for(int i=0;i<g[u].size();i++){
//            int v=g[u][i];
//            dfs(v);
//        }
//    }
    int query(){
        int fir,las,sum=0;
        if(t0.length()!=t1.length())return 0;
        int p0=0,p1=0,len=t0.length();
        for(int i=0;i<len;i++){
            if(t0[i]!=t1[i]){fir=i;break;}
        }
        for(int i=len-1;i>=0;i--){
            if(t0[i]!=t1[i]){las=i;break;}
        }
        for(int i=0;i<len;i++){
            int c0=t0[i]-'a',c1=t1[i]-'a';
            p0=nxt[p0][c0];p1=nxt[p1][c1];
            if(i>=las){//cout<<i<<endl;
                set<int>v;
                for(int j=p0;j;j=fail[j]){
                    if(dep[j]<i-fir+1)break;
                    for(int k=0;k<val[0][j].size();k++){
                        v.insert(val[0][j][k]);
                        //vis[val[0][j][k]]=1;//cout<<"WIN"<<val[0][j][k]<<endl;
                    }
                }
                for(int j=p1;j;j=fail[j]){
                    if(dep[j]<i-fir+1)break;
                    for(int k=0;k<val[1][j].size();k++){
                        if(v.find(val[1][j][k])!=v.end())sum++,v.erase(val[1][j][k]);
                    }
                }
            }
        }return sum;
    }
}IS;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;IS.tot=0;
    for(int i=1;i<=n;i++){cin>>s[i][0]>>s[i][1];IS.ins(0,s[i][0],i);IS.ins(1,s[i][1],i);}
    IS.init();
    for(int i=1;i<=q;i++){cin>>t0>>t1;
        cout<<IS.query()<<endl;
    }

    return 0;
}
//2 1
//xabcx xadex
//bc de
//xabcx xadex
