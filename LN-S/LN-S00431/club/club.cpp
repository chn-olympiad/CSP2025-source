#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
const int N=1e5+10;
vector<pair<int,int>>g1,g2,g3;
struct node{
    int a,b,c,maxx,st,minn,ch,maxn;
}g[N];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        for(int i=1;i<=N;i++){
            g1.clear();
            g2.clear();
            g3.clear();
            g[i].a=0;
            g[i].b=0;
            g[i].c=0;
            g[i].maxx=0;
            g[i].st=0;
            g[i].minn=0;
            g[i].ch=0;
            g[i].maxn=-1;
        }
        int res=0;
        cin>>n;

        for(int i=1;i<=n;i++){
            cin>>g[i].a>>g[i].b>>g[i].c;
            int a=g[i].a,b=g[i].b,c=g[i].c;
            int maxn=max(a,max(b,c));
            res+=maxn;
            if(maxn==a){
                g[i].maxn=maxn;
                g1.push_back({a,i});
                g[i].maxx=max(b,c);
                if(b>=c) g[i].st=2;
                else g[i].st=3;
                g[i].minn=min(b,c);
                g[i].ch=maxn-g[i].maxx;
            }
            else if(maxn==b){
                g[i].maxn=maxn;
                g2.push_back({b,i});
                g[i].maxx=max(a,c);
                g[i].minn=min(a,c);
                if(a>=c) g[i].st=1;
                else g[i].st=3;
                g[i].ch=maxn-g[i].maxx;
            }
            else if(maxn==c){
                g[i].maxn=maxn;
                g3.push_back({c,i});
                g[i].maxx=max(b,a);
                g[i].minn=min(b,a);
                if(b>=a) g[i].st=2;
                else g[i].st=1;
                g[i].ch=maxn-g[i].maxx;
            }
        }

        if(g1.size()>n/2){
            sort(g1.rbegin(),g1.rend());
            while(g1.size()>n/2){
                auto t=g1.back();
                int u=t.first;
                int v=t.second;
                int ma=g[v].maxx,mi=g[v].minn;
                bool flag=0;
                for(auto tt:g1){
                    int ss=tt.first;
                    int s2=tt.second;
                    if(g[s2].maxx>u){
                        //cout<<ss<<" "<<g[s2].a<<" "<<g[s2].b<<" "<<g[s2].c<<"\n";
                        res-=g[s2].maxn;
                        res+=max(g[s2].b,g[s2].c);
                        flag=1;
                        break;
                    }
               }
               if(!flag){
                    res+=ma;
                    res-=u;
               }
                if(g[v].st==2) g2.push_back({ma,v});
                else g3.push_back({ma,v});
                g1.pop_back();
            }
        }
        if(g2.size()>n/2){
            sort(g2.rbegin(),g2.rend());
            while(g2.size()>n/2){
                    //cout<<"___";
                auto t=g2.back();
                int u=t.first;
                int v=t.second;
                int ma=g[v].maxx,mi=g[v].minn;
                bool flag=0;
                for(auto tt:g2){
                    int ss=tt.first;
                    int s2=tt.second;
                    if(g[s2].maxx>u){
                        //cout<<ss<<" "<<g[s2].a<<" "<<g[s2].b<<" "<<g[s2].c<<"\n";
                        res-=g[s2].maxn;
                        res+=max(g[s2].a,g[s2].c);
                        flag=1;
                        break;
                    }
               }
               if(!flag){
                    res+=ma;
                    res-=u;
               }
                if(g[v].st==1) g1.push_back({ma,v});
                else g3.push_back({ma,v});
                g2.pop_back();
            }
        }
        if(g3.size()>n/2){

            sort(g3.rbegin(),g3.rend());
            while(g3.size()>n/2){
                auto t=g3.back();
                int u=t.first;
                int v=t.second;
                int ma=g[v].maxx,mi=g[v].minn;
                bool flag=0;
                for(auto tt:g3){
                    int ss=tt.first;
                    int s2=tt.second;
                    if(g[s2].maxx>u){
                        //cout<<ss<<" "<<g[s2].a<<" "<<g[s2].b<<" "<<g[s2].c<<"\n";
                        res-=g[s2].maxn;
                        res+=max(g[s2].b,g[s2].a);
                        flag=1;
                        break;
                    }
               }
               if(!flag){
                    res+=ma;
                    res-=u;
               }
                if(g[v].st==2) g2.push_back({ma,v});
                else g1.push_back({ma,v});
                g3.pop_back();
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}
