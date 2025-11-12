#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+7;
int T,n;
int ans;
struct node{
    int a;
    int b;
    int c;
    int maxx;
    int val;
    int idx;
}nodes[N];
bool cmp(node s1,node s2){
    return s1.val<s2.val;
}
map<int,int> mp;
int check(node k){
    if(k.idx==1) {
        if(k.b>=k.c) return k.b;
        else return k.c;
    }else if(k.idx==2) {
        if(k.a>=k.c) return k.a;
        else return k.c;
    }else{
        if(k.a>=k.b) return k.a;
        else return k.b;
    }
}
vector<node> A;
vector<node> B;
vector<node> C;
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--){
        A.clear();
        B.clear();
        C.clear();
        ans=0;
        mp.clear();
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>nodes[i].a>>nodes[i].b>>nodes[i].c;
            if(nodes[i].a>=nodes[i].b&&nodes[i].a>=nodes[i].c) nodes[i].idx=1,nodes[i].maxx=nodes[i].a;
            else if(nodes[i].b>=nodes[i].a&&nodes[i].b>=nodes[i].c) nodes[i].idx=2,nodes[i].maxx=nodes[i].b;
            else if(nodes[i].c>=nodes[i].b&&nodes[i].c>=nodes[i].a) nodes[i].idx=3,nodes[i].maxx=nodes[i].c;
            mp[nodes[i].idx]++;
            ans+=nodes[i].maxx;
            nodes[i].val=nodes[i].maxx-check(nodes[i]);
            if(nodes[i].idx==1) A.push_back(nodes[i]);
            else if(nodes[i].idx==2) B.push_back(nodes[i]);
            else C.push_back(nodes[i]);
        }
        int j=0;
        if(mp[1]>n/2){
            sort(A.begin(),A.end(),cmp);
            while(mp[1]>n/2){
                mp[1]--;
                ans-=A[j].val;
                j++;
            }
        }else if(mp[2]>n/2){
            sort(B.begin(),B.end(),cmp);
            while(mp[2]>n/2){
                mp[2]--;
                ans-=B[j].val;
                j++;
            }
        }else if(mp[3]>n/2){
            sort(C.begin(),C.end(),cmp);
            while(mp[3]>n/2){
                mp[3]--;
                ans-=C[j].val;
                j++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
