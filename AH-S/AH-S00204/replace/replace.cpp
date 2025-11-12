#include<bits/stdc++.h>
using namespace std;
int n,m,flag[200005];
string a[200005],b[200005],st,ed;
queue<string> q;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    while(m--){
        map<string,int> f;
        map<string,bool> vis;
        cin>>st>>ed;
        q.push(st);
        while(!q.empty()){
            string x=q.front();q.pop();
            for(int i=1;i<=n;i++){
                int t=x.find(a[i]);
                if(t!=-1){
                    string tmp=x;
                    tmp.erase(t,a[i].size());
                    tmp.insert(t,b[i]);
                    f[tmp]++;
                    if(!vis[tmp]){
                        vis[tmp]=1;
                    }
                }
            }
        }
        cout<<f[ed]<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
