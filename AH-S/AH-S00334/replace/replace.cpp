#include<bits/stdc++.h>
using namespace std;
int n,q;
const int N=2e+3+5;
string s1[N],s2[N];
int nxt1[N][N],nxt2[N][N];
int pos1[N],cnt1,pos2[N],cnt2;
void getnxt(string s,int *nxt){
    int len=s.size();
    s=" "+s;
    for(int i=2;i<=len;i++){
        int j=nxt[i-1];
        while(j>0&&s[i]!=s[j+1]) j=nxt[j];
        if(s[i]==s[j+1]) j++;
        nxt[i]=j;
    }
   // for(int i=1;i<=len;i++) cout<<nxt[i]<<' '; cout<<'\n';
}
void kmp(string s,string t,int *pos,int &cnt,int *nxt){
    int len1=s.size(),len2=t.size();
    s=" "+s;
    t=" "+t;
    for(int i=1,j=1;i<=len1;i++){
        while(j>0&&s[i]!=t[j+1]) j=nxt[j];
        if(s[i]==t[j+1]) j++;
        if(j==len2) pos[++cnt]=i-len2+1,j=nxt[j];//,cout<<pos[cnt]<<' ';
    }
  //  cout<<'\n';
}
struct ret{int cnt,lenx,idx;};
ret Init(string t1,string t2){
    int cnt=0,len=t1.size(),idx=-1;
    int lenx=0;
    if(len!=t2.size())
        return ret{1,len,1};
    for(int i=0;i<len;i++)
        if(i==0||(t1[i]!=t2[i]&&t1[i-1]==t2[i-1]))
          cnt++,lenx++,idx=i+1;
        else if(t1[i]!=t2[i]) lenx++;
    return ret{cnt,lenx,idx};
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>s1[i]>>s2[i],
        getnxt(s1[i],nxt1[i]),getnxt(s2[i],nxt2[i]);
    for(int i=1;i<=q;i++){
        string t1,t2;
        cin>>t1>>t2;
        ret tmp=Init(t1,t2);
        if(tmp.cnt>1){
            cout<<"0\n";
            continue;
        }
        int ans=0;
        int len=tmp.lenx,idx=tmp.idx;
     //   cout<<len<<' '<<idx<<'\n';
        for(int i=1;i<=n;i++) {
            if(s1[i].size()!=len) continue;
       //     cout<<i<<'\n';
            cnt1=cnt2=0;
            kmp(t1,s1[i],pos1,cnt1,nxt1[i]);
            kmp(t2,s2[i],pos2,cnt2,nxt2[i]);
            int k1=lower_bound(pos1+1,pos1+cnt1+1,idx)-pos1;
            int k2=lower_bound(pos2+1,pos2+cnt2+1,idx)-pos2;
            if(!cnt1||!cnt2) continue;
            if(k1<=cnt1&&k2<=cnt2&&pos1[k1]==pos2[k2]) ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
