#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c,diff,idx,chs;
    void input(int i){
        cin>>a>>b>>c;
        diff=max({a,b,c})-a-b-c+max({a,b,c})+min({a,b,c});
        idx=i;
    }
    const bool operator <(const node _) const{
        return diff>_.diff;
    } 
}stu[100005];
bool cmp(node a,node b){
        return a.idx<b.idx;
    }
void solve(){
    int n,sta=0,stb=0,stc=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) stu[i].input(i);
    sort(stu+1,stu+n+1);
    for(int i=1;i<=n;i++){
        if(sta*2==n) {
            if(stu[i].b>stu[i].c) stb++,ans+=stu[i].b,stu[i].chs=2;
            else ans+=stu[i].c,stc++,stu[i].chs=3;
        }else if(stb*2==n){
            if(stu[i].a>stu[i].c) ans+=stu[i].a,sta++,stu[i].chs=1;
            else ans+=stu[i].c,stc++,stu[i].chs=3;
        }else if(stc*2==n){
            if(stu[i].a>stu[i].b) ans+=stu[i].a,sta++,stu[i].chs=1;
            else ans+=stu[i].b,stb++,stu[i].chs=2;
        }else{
            if(stu[i].a>max(stu[i].b,stu[i].c))ans+=stu[i].a,sta++,stu[i].chs=1;
            else{
                if(stu[i].b>stu[i].c)stb++,ans+=stu[i].b,stu[i].chs=2;
                else stc++,ans+=stu[i].c,stu[i].chs=3;
            }
        }
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}