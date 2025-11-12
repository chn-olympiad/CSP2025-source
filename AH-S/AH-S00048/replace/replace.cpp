#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q,flag;
string t1,t2;
struct Node{
    int pre,nxt;
};
unordered_map<int,vector<Node> >a;
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>t1>>t2;
        int bg,ed;
        for(bg=0;t1[bg]!='b';bg++);
        for(ed=0;t2[ed]!='b';ed++);
        Node tmp;
        tmp.pre=bg;tmp.nxt=t1.size()-ed;
        a[ed-bg].push_back(tmp);
    }
    while(q--){
        cin>>t1>>t2;
        if(t1.size()!=t2.size())
        {
            cout<<0<<endl;
            continue;
        }
        int ans=0;
        int bg,ed;
        for(bg=0;t1[bg]!='b';bg++);
        for(ed=0;t2[ed]!='b';ed++);
        for(auto i:a[ed-bg])
            if(i.pre<=bg&&i.nxt<=t1.size()-ed) ans++;
        cout<<ans<<endl;
    }
    return 0;
}

