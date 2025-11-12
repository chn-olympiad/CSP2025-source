#include <bits/stdc++.h>
using namespace std;
/*
this is a HARD problem
I am very poor at string
但我有想法：
一个变换可以=X%Y->X^Y
一个q也是
找到%^一样的分开算
按前缀排序然后可持久化trie
不过时间不够直接暴力


我是baka吗??????这就是AC自动机的题啊！！！！！！！！！！
这是板子啊啊啊啊啊啊啊

NOTIMESLEFT...
rip 60pts
*/
unordered_map<int,int>hd;
int la[200010];
int lx[200010],ly[200010],hx[200010],hy[200010];
const int mod=998244353,bs=83;
string t1,t2;
int n,q;
string to,we;
long long hs;
void mash(){
    if(t1==t2){
        hs=-1;
        return;
    }
    to="";
    we="";
    int l=0,r1=t1.size()-1,r2=t2.size()-1;
    while(l<t1.size()&&l<t2.size()){
        if(t1[l]==t2[l]){
            to=to+t1[l];
            t1[l]='#';
            t2[l]='#';
            l++;
        }else break;
    }
    reverse(to.begin(),to.end());
    while(r1>=0&&r2>=0){
        if(t1[r1]=='#')break;
        if(t2[r2]==t1[r1]){
            we=we+t2[r2];
            t1[r1]='#';
            t2[r2]='#';
            r2--;
            r1--;
        }else break;
    }
    reverse(we.begin(),we.end());
    hs=0;
    for(int i=l;i<t1.size();i++){
        if(t1[i]=='#')break;
        hs*=bs;
      //  cout<<t1[i];
        hs+=t1[i]-'a'+1;
        hs%=mod;
    }
    //cout<<"#";
    hs*=bs;
    hs+=27;
    hs%=mod;
    for(int i=l;i<t2.size();i++){
        if(t2[i]=='#')break;
     //   cout<<t2[i];
        hs*=bs;
        hs+=t2[i]-'a'+1;
        hs%=mod;
    }
   // cout<<endl;
    //cout<<to<<' '<<we<<endl;
    return;
}
int gths(string &s){
    int ret=0;
    for(int i=0;i<s.size();i++){
        ret*=bs;
        ret+=s[i]-'a'+1;
        ret%=mod;
    }
    return ret;
}
int cnt;
int hsx[5000100],hsy[5000100];
int main(){

  freopen("replace.in","r",stdin);
   freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>t1>>t2;
        mash();
      //  cout<<i<<" - "<<hs<<endl;
        if(hs==-1)continue;
        la[i]=hd[hs];
        hd[hs]=i;

        lx[i]=to.size();
        ly[i]=we.size();
        hx[i]=gths(to);
        hy[i]=gths(we);
    }
    int pl,ans;
    while(q--){
        cin>>t1>>t2;
        mash();
        ans=0;
        pl=hd[hs];
        for(int i=0;i<to.size();i++){
            hsx[i+1]=hsx[i]*bs+to[i]-'a'+1;
            hsx[i+1]%=mod;
        }
        for(int i=0;i<we.size();i++){
            hsy[i+1]=hsy[i]*bs+we[i]-'a'+1;
            hsy[i+1]%=mod;
        }
      //  cout<<hs<<endl;
        while(pl){
       //         cout<<pl<<endl;
            if(lx[pl]>to.size()||ly[pl]>we.size()){
                pl=la[pl];
                continue;
            }
            if(hsx[lx[pl]]==hx[pl]&&hsy[ly[pl]]==hy[pl]){
                ans++;
            }
            pl=la[pl];
        }
        cout<<ans<<endl;
    }
    return 0;
}
