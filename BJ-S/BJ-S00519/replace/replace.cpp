#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int L=5000010;
int n,q;
char a[L],b[L];
struct node{
    int ch[26],fail;
    int cnt;
}t[L];
int tot;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>q;
    while(n--){
        cin>>a+1>>b+1;
        int p=0;
        for(int i=1;a[i];i++){
            int c=a[i]-'a';
            if(!t[p].ch[c])t[p].ch[c]=++tot;
            p=t[p].ch[c];
            c=b[i]-'a';
            if(!t[p].ch[c])t[p].ch[c]=++tot;
            p=t[p].ch[c];
        }
        t[p].cnt++;
    }
    queue<int> qq;
    for(int i=0;i<26;i++)if(t[0].ch[i])qq.push(t[0].ch[i]);
    while(!qq.empty()){
        int u=qq.front();
        qq.pop();
        for(int i=0;i<26;i++){
            int f=t[t[u].fail].ch[i];
            if(t[u].ch[i]){
                t[t[u].ch[i]].fail=f;
                qq.push(t[u].ch[i]);
                t[t[u].ch[i]].cnt+=t[f].cnt;
            }
            else t[u].ch[i]=f;
        }
    }
    while(q--){
        cin>>a+1>>b+1;
        int len=strlen(a+1);
        if(strlen(b+1)!=len){
            cout<<0<<'\n';
            continue;
        }
        int mn=0,mx=0;
        for(int i=1;i<=len;i++){
            if(a[i]==b[i])continue;
            if(!mn)mn=i;
            mx=i;
        }
        ll ans=0;
        int p=0;
        for(int i=1;i<=len;i++){
            p=t[t[p].ch[a[i]-'a']].ch[b[i]-'a'];
            if(i>=mx)ans+=t[p].cnt;
        }
        p=0;
        for(int i=mn+1;i<=len;i++){
            p=t[t[p].ch[a[i]-'a']].ch[b[i]-'a'];
            if(i>=mx)ans-=t[p].cnt;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
