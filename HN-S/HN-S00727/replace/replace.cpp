#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int MAXN=2e5+10;
const int N=5e6+10;
const int base=133131;
int n,m;
struct node{
    string s1,s2;
}q[MAXN];
ull pw[N];
unordered_map<ull,int>mp;
vector<int>vec[N];
ull mk(ull x,ull y){
    return x*1145141ull+y;
}
int len1,len2;
ull hsh1[MAXN],hsh2[MAXN];
string str1[MAXN],str2[MAXN];
ull get_hash1(int l,int r){
    return hsh1[r]-hsh1[l-1]*pw[r-l+1];
}
ull get_hash2(int l,int r){
    return hsh2[r]-hsh2[l-1]*pw[r-l+1];
}
struct Node{
    int len,x,y,id;
}a[MAXN],b[MAXN];
bool cmp(Node x,Node y){
    return x.len<y.len;
}
ll res[MAXN];
bool vis[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m; 
    for(int i=1;i<=n;i++){
        cin>>str1[i]>>str2[i];
    }
    for(int i=1;i<=m;i++){
        cin>>q[i].s1>>q[i].s2;len2+=q[i].s1.size()*2;
    }
    if(len2<=2000){
        pw[0]=1; for(int i=1;i<=len2;i++) pw[i]=pw[i-1]*base;
        for(int i=1;i<=n;i++){
            ull hs=0,hs1=0;
            for(int j=0;j<str1[i].size();j++) hs=hs*base+str1[i][j];
            for(int j=0;j<str2[i].size();j++) hs1=hs1*base+str2[i][j];
            mp[mk(hs,hs1)]++;
        }
        for(int i=1;i<=m;i++){
            for(int j=0;j<q[i].s1.size();j++) hsh1[j+1]=hsh1[j]*base+q[i].s1[j];
            for(int j=0;j<q[i].s2.size();j++) hsh2[j+1]=hsh2[j]*base+q[i].s2[j];
            int pre=0,suf=-1;
            for(int j=0;j<q[i].s1.size();j++){
                if(q[i].s1[j]!=q[i].s2[j]){
                    pre=j+1;break;
                }
            }if(!pre) pre=q[i].s1.size();
            for(int j=q[i].s1.size()-1;j>=0;j--){
                if(q[i].s1[j]!=q[i].s2[j]){
                    suf=j+1;break;
                }
            }ll ans=0;
            if(suf<=1) suf=1;
            for(int j=pre;j>=1;j--){
                for(int k=max(suf,j);k<=q[i].s2.size();k++){
                    ans+=mp[mk(get_hash1(j,k),get_hash2(j,k))];
                }
            }cout<<ans<<'\n';
        }
    }
    else{
        for(int i=1;i<=n;i++){
            int fi,se;
            for(int j=0;j<str1[i].size();j++){
                if(str1[i][j]=='b') fi=j;
            }
            for(int j=0;j<str2[i].size();j++){
                if(str2[i][j]=='b') se=j;
            }int ls=str2[i].size()-se-1;
           a[i]=(Node){se-fi+1,fi,ls,i};
        }sort(a+1,a+1+n,cmp);
        for(int i=1;i<=m;i++){
            int fi,se;
            for(int j=0;j<q[i].s1.size();j++) if(q[i].s1[j]=='b') fi=j;
            for(int j=0;j<q[i].s2.size();j++) if(q[i].s2[j]=='b') se=j;
            int ls=q[i].s2.size()-se-1;
            b[i]=(Node){se-fi+1,fi,ls,i};
        }
        sort(b+1,b+1+m,cmp);int lst=-2e9;stack<int>stk;int pos=0;
        for(int i=1;i<=m;i++){
            if(lst!=b[i].len){
                lst=b[i].len;
                while(stk.size()){
                    vec[stk.top()].clear();
                    vis[stk.top()]=0;
                    stk.pop();
                }queue<int>q;
                while(pos<n&&a[pos+1].len<=b[i].len){
                    pos++;  
                    if(a[pos].len==b[i].len) {
                        vec[a[pos].x].push_back(a[pos].y);
                        if(!vis[a[pos].x]){
                            stk.push(a[pos].x);vis[a[pos].x]=1;q.push(a[pos].x);
                        }
                    }
                }
                while(q.size()){
                    sort(vec[q.front()].begin(),vec[q.front()].end());q.pop();
                }
            }
            for(int j=b[i].x;j>=0;j--){
                res[b[i].id]+=upper_bound(vec[j].begin(),vec[j].end(),b[i].y)-vec[j].begin();
            }
        }
        for(int i=1;i<=m;i++) cout<<res[i]<<'\n';
    }
    return 0;
}