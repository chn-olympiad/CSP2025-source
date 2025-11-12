#include<bits/stdc++.h>
using namespace std;
const int N=2e5,L=5e6;
int n,q;
string sl,sr;
int ch[2*L+5][26],cnt=L,tag[N+5];
vector<int> rec[2*L+5][2];
int head[2*L+5][2],nxt[2*N+5],num[2*N+5],vist;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int o=1;o<=n;o++){
        cin>>sl>>sr; int len=sl.length();
        if(sl==sr) continue;
        int l,r;
        for(int i=0;i<len;i++){
            if(sl[i]!=sr[i]){l=i; break;}
        }
        for(int i=len-1;i>=0;i--){
            if(sl[i]!=sr[i]){r=i; break;}
        }
        int pos=r-l+1;
        for(int i=r;i>=0;i--){
            if(ch[pos][sl[i]-'a']==0) ch[pos][sl[i]-'a']=++cnt;
            pos=ch[pos][sl[i]-'a'];
        }
        nxt[++vist]=head[pos][0],head[pos][0]=vist,num[vist]=o;
        pos=r-l+1;
        for(int i=l;i<len;i++){
            if(ch[pos][sr[i]-'a']==0) ch[pos][sr[i]-'a']=++cnt;
            pos=ch[pos][sr[i]-'a'];
        }
        nxt[++vist]=head[pos][1],head[pos][1]=vist,num[vist]=o;
    }
    for(int o=1;o<=q;o++){
        cin>>sl>>sr; int ans=0;
        if(sl.length()!=sr.length()){cout<<0<<"\n"; continue;}
        int len=sl.length(),l,r;
        for(int i=0;i<len;i++){
            if(sl[i]!=sr[i]){l=i; break;}
        }
        for(int i=len-1;i>=0;i--){
            if(sl[i]!=sr[i]){r=i; break;}
        }
        int pos=r-l+1;
        for(int i=r;i>=0;i--){
            if(ch[pos][sl[i]-'a']==0) ch[pos][sl[i]-'a']=++cnt;
            pos=ch[pos][sl[i]-'a'];
            if(i<=l){
                for(int j=head[pos][0];j;j=nxt[j]) tag[num[j]]=o;
            }
        }
        pos=r-l+1;
        for(int i=l;i<len;i++){
            if(ch[pos][sr[i]-'a']==0) ch[pos][sr[i]-'a']=++cnt;
            pos=ch[pos][sr[i]-'a'];
            if(i>=r){
                for(int j=head[pos][1];j;j=nxt[j]) ans+=(tag[num[j]]==o);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}