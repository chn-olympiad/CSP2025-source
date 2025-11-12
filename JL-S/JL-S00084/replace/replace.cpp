#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define puu pair<ull,ull>
using namespace std;
const int N=200010,P=131,M=5000010;
int n,q,id_cnt;
ull L[M],R[M];
string s[N][2],t[2];
map<puu,int> mp;
struct Node{
    int lenl,lenr;
    ull left,right;
};
bool cmp(Node x,Node y){
    if(x.lenl==y.lenl){
        if(x.left!=y.left) return x.left<y.left;
        return x.lenr<y.lenr;
    }
    return x.lenl<y.lenl;
}
vector<Node> v[N];
void work(int id){
    if(s[id][0]==s[id][1]) return;
    int len=s[id][0].size();
    int l=-1,r=-1;
    for(int i=0;i<len;i++){
        if(s[id][0][i]!=s[id][1][i]){
            r=i;
            if(l==-1) l=i;
        }
    }
    ull pre=0,now=0;
    for(int i=l;i<=r;i++){
        pre=pre*P+s[id][0][i]-'a'+1;
        now=now*P+s[id][1][i]-'a'+1;
    }
    ull left=0,right=0;
    for(int i=0;i<l;i++) left=left*P+s[id][0][i]-'a'+1;
    for(int i=r+1;i<len;i++) right=right*P+s[id][1][i]-'a'+1;
    if(!mp[{pre,now}]) mp[{pre,now}]=++id_cnt;
    int Id=mp[{pre,now}];
    v[Id].push_back({l,len-1-r,left,right});
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin.tie(0),cout.tie(0);ios::sync_with_stdio(false);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1],work(i);
    for(int i=1;i<=id_cnt;i++) sort(v[i].begin(),v[i].end(),cmp);
    while(q--){
        int ans=0;
        cin>>t[0]>>t[1];
        if(t[0].size()!=t[1].size()){
            cout<<"0\n";
            continue;
        }
        int len=t[0].size(),l=-1,r=-1;
        for(int i=0;i<len;i++){
            if(t[0][i]!=t[1][i]){
                if(l==-1) l=i;
                r=i;
            }
        }
        ull pre=0,now=0;
        for(int i=l;i<=r;i++){
            pre=pre*P+t[0][i]-'a'+1;
            now=now*P+t[1][i]-'a'+1;
        }
        if(!mp[{pre,now}]){
            cout<<"0\n";
            continue;
        }
        int Id=mp[{pre,now}];
        ull pp=1;
        L[0]=R[0]=0;
        for(int lenl=1,pos=l-1;lenl<=l;lenl++,pos--,pp*=P){
            L[lenl]=L[lenl-1]+pp*(t[0][pos]-'a'+1);
        }
        for(int lenr=1,pos=r+1;pos<len;lenr++,pos++){
            R[lenr]=R[lenr-1]*P+t[0][pos]-'a'+1;
        }
        for(Node awa:v[Id]){
            if(awa.lenl>l) break;
            if(L[awa.lenl]!=awa.left) continue;
            if(awa.lenr>len-1-r) continue;
            if(R[awa.lenr]!=awa.right) continue;
            ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}