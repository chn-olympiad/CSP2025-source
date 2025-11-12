#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
vector<int>uset(10010),csts(1000010);
stack<int>upt[10010];
map<int,stack<pair<int,int>>> mp;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)uset[i]=i,upt[i].push(i);
    for (int i=1;i<=m;i++){
        int x,y,c;
        cin>>x>>y>>c;
        mp[c].push((pair<int,int>){x,y});
        csts[i]=c;
    }
    sort(csts.begin()+1,csts.begin()+1+m);
    for (int i=1;i<=m;i++){
        while(mp[csts[i]].size()){
            int x=mp[csts[i]].top().first,y=mp[csts[i]].top().second;
            mp[csts[i]].pop();
            while(uset[y]!=uset[uset[y]])uset[y]=uset[uset[y]];
            while(uset[x]!=uset[uset[x]])uset[x]=uset[uset[x]];
            if (uset[x]!=uset[y]){
 //               if (upt[x].size()>=upt[y].size()){
                    upt[uset[x]].push(uset[y]);
                    while(upt[uset[y]].size()&&uset[y]!=uset[x]){
                        upt[uset[x]].push(upt[uset[y]].top());
                        if (upt[uset[y]].top()!=uset[y])uset[upt[uset[y]].top()]=uset[x];
                        upt[uset[y]].pop();
                    }
                    ans+=csts[i];
                    uset[y]=uset[x];
 //               }
                /*else{
                    uset[x]=uset[y];
                    upt[uset[y]].push(x);
                    while(upt[x].size()){
                        upt[uset[y]].push(upt[x].top());
                        uset[upt[x].top()]=uset[y];
                        upt[x].pop();
                    }
                    ans+=csts[i];
                }*/
            }
        }
    }
    cout<<ans;
}
