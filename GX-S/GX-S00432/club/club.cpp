#include<bits/stdc++.h>
using namespace std;
int n;
struct range{
    int a,b,c;
}r[10001];
bool cmp(int x,int y){return x<y;}
void solve(){
    int n,ans;
    vector<int> c1,c2,c3,m;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>r[i].a>>r[i].b>>r[i].c;
        m.push_back(i);
    }
    while(!m.empty()){
        int u = m.back();
        int s;
        m.pop_back();
        s=max(r[u].a,r[u].b);
        s=max(s,r[u].c);
        if(s==r[u].a){
            if(c1.size()<=n/2){
                c1.push_back(s);
                ans+=s;
                continue;
            }
            else{
                s = max(r[u].b,r[u].c);
            }
        }

        if(s==r[u].b){
            if(c2.size()<=n/2){
                c2.push_back(s);
                ans+=s;
                continue;
            }
            else{
                s = r[u].c;
            }
        }

        if(s==r[u].c){
            if(c3.size()<=n/2){
                c3.push_back(s);
                ans+=s;
                continue;
            }
            else{
                s = max(r[u].a,r[u].b);
            }
        }

        if(s==r[u].a){
            if(c1.size()<=n/2){
                c1.push_back(s);
                ans+=s;
                continue;
            }
            else{
                s =r[u].b;
            }
        }

        if(s==r[u].b){
            if(c2.size()<=n/2){
                c2.push_back(s);
                ans+=s;
                continue;
            }
        }
    }
    cout<<ans;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
