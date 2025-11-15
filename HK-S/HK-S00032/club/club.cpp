#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
    int t;cin>>t;vector<int>ans;
    for(int i=0;i<t;i++){
        int n,mns=0;cin>>n;
        vector<vector<int>>a(n,vector<int>(3,0));
        vector<tuple<int,int,int>>b;
        vector<vector<pair<int,int>>>d(3,vector<pair<int,int>>());
        for(int k=0;k<n;k++){
            cin>>a[k][0]>>a[k][1]>>a[k][2];
            b.push_back({a[k][0],k,0});
            b.push_back({a[k][1],k,1});
            b.push_back({a[k][2],k,2});
        }
        sort(b.begin(),b.end());reverse(b.begin(),b.end());
        vector<bool>c(n,false);
        for(int k=0;k<b.size();k++){
            if(!c[get<1>(b[k])]){
                c[get<1>(b[k])]=true;
                d[get<2>(b[k])].push_back({get<0>(b[k]),get<1>(b[k])});
            }
        }
        if(d[0].size()>n/2){
                int u=d[0].size();
            vector<tuple<int,int,int>>e;
            for(int k=0;k<d[0].size();k++){
                e.push_back({d[0][k].first-a[d[0][k].second][1],d[0][k].second,1});
                e.push_back({d[0][k].first-a[d[0][k].second][2],d[0][k].second,2});
            }
            sort(e.begin(),e.end());
            vector<bool>f(n,false);
            for(int k=0;k<e.size(),u>n/2;k++){
                if(!f[get<1>(e[k])]){
                    u--;
                    f[get<1>(e[k])]=true;
                    mns+=a[get<1>(e[k])][0];
                    d[get<2>(e[k])].push_back({a[get<1>(e[k])][get<2>(e[k])],get<1>(e[k])});
                }
            }
        }else if(d[1].size()>n/2){
                int u=d[1].size();
            vector<tuple<int,int,int>>e;
            for(int k=0;k<d[1].size();k++){
                e.push_back({d[1][k].first-a[d[1][k].second][0],d[1][k].second,0});
                e.push_back({d[1][k].first-a[d[1][k].second][2],d[1][k].second,2});
            }
            sort(e.begin(),e.end());
            vector<bool>f(n,false);
            for(int k=0;k<e.size(),u>n/2;k++){
                if(!f[get<1>(e[k])]){
                    u--;
                    f[get<1>(e[k])]=true;
                    mns+=a[get<1>(e[k])][1];
                    d[get<2>(e[k])].push_back({a[get<1>(e[k])][get<2>(e[k])],get<1>(e[k])});
                }
            }
        }else if(d[2].size()>n/2){
                int u=d[2].size();
            vector<tuple<int,int,int>>e;
            for(int k=0;k<d[2].size();k++){
                e.push_back({d[2][k].first-a[d[2][k].second][1],d[2][k].second,1});
                e.push_back({d[2][k].first-a[d[2][k].second][0],d[2][k].second,0});
            }
            sort(e.begin(),e.end());
            vector<bool>f(n,false);
            for(int k=0;k<e.size(),u>n/2;k++){
                if(!f[get<1>(e[k])]){
                    u--;
                    f[get<1>(e[k])]=true;
                    mns+=a[get<1>(e[k])][2];
                    d[get<2>(e[k])].push_back({a[get<1>(e[k])][get<2>(e[k])],get<1>(e[k])});
                }
            }
        }
        mns*=-1;
        for(int k=0;k<3;k++){
            for(int l=0;l<d[k].size();l++){
                mns+=d[k][l].first;
            }
        }ans.push_back(mns);

    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\n";
    }

fclose(stdin);fclose(stdout);

}

