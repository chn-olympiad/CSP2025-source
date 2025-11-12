#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const int N=200005;
const int M=2000005;
const ull P=13331;
int n,q,lp[N],rp[N],vis1[N][4]={},vis2[N][4]={},ans,tag[N];
ull w1[N][4],w2[N][4];
string s[N][2],t[N][2];
ull hx1[M],hx2[M],wei[M];
map<ull,int> o1,o2;
inline ull get(int l,int r,int id){
    if(id==0){
        if(l)return hx1[r]-hx1[l-1]*wei[r-l+1];
        else return hx1[r];
    }
    else{
        if(l)return hx2[r]-hx2[l-1]*wei[r-l+1];
        else return hx2[r];
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    wei[0]=1;
    for(int i=1;i<=2000000;++i)wei[i]=wei[i-1]*P;
    for(int i=1;i<=n;++i)cin>>s[i][0]>>s[i][1];
    for(int i=1;i<=q;++i)cin>>t[i][0]>>t[i][1];
    for(int i=1;i<=n;++i){
        hx1[0]=s[i][0][0]-'a',hx2[0]=s[i][1][0]-'a';
        for(int j=1;j<s[i][0].size();++j)hx1[j]=hx1[j-1]*P+(s[i][0][j]-'a'),hx2[j]=hx2[j-1]*P+(s[i][1][j]-'a');
        if(s[i][0]==s[i][1]){tag[i]=1;continue;}
        for(int j=0;j<s[i][0].size();++j)if(s[i][0][j]!=s[i][1][j])rp[i]=j;
        for(int j=s[i][0].size()-1;j>=0;--j)if(s[i][0][j]!=s[i][1][j])lp[i]=j;
        if(lp[i]!=0)w1[i][0]=get(0,lp[i]-1,0);
        else vis1[i][0]=1;
        w1[i][1]=get(lp[i],rp[i],0);w1[i][2]=get(lp[i],rp[i],1);
        if(rp[i]!=s[i][0].size()-1)w1[i][3]=get(rp[i]+1,s[i][0].size()-1,0);
        else vis1[i][3]=1;
        //cout<<i<<endl;
        //cout<<w1[i][0]<<" "<<w1[i][1]<<" "<<w1[i][2]<<" "<<w1[i][3]<<endl;
    }
    //if((n<=10000&&q<=10000)||q==1){
        for(int i=1;i<=q;++i){
            ans=0;
            hx1[0]=t[i][0][0]-'a',hx2[0]=t[i][1][0]-'a';
            for(int j=1;j<t[i][0].size();++j)hx1[j]=hx1[j-1]*P+(t[i][0][j]-'a'),hx2[j]=hx2[j-1]*P+(t[i][1][j]-'a');
            for(int j=0;j<t[i][0].size();++j)if(t[i][0][j]!=t[i][1][j])rp[i]=j;
            for(int j=t[i][0].size()-1;j>=0;--j)if(t[i][0][j]!=t[i][1][j])lp[i]=j;
            if(lp[i]!=0)w2[i][0]=get(0,lp[i]-1,0);
            else vis2[i][0]=1;
            w2[i][1]=get(lp[i],rp[i],0);w2[i][2]=get(lp[i],rp[i],1);
            if(rp[i]!=t[i][0].size()-1)w2[i][3]=get(rp[i]+1,t[i][0].size()-1,0);
            else vis2[i][3]=1;
            o1.clear();o2.clear();
            for(int j=0;j<lp[i];++j)o1[get(0,j,0)]=1;
            for(int j=rp[i]+1;j<t[i][0].size();++j)o2[get(j,t[i][0].size()-1,0)]=1;
            for(int j=1;j<=n;++j){
                if(tag[j])continue;
                if(w1[j][1]!=w2[i][1]||w1[j][2]!=w2[i][2])continue;
                if(!(vis1[j][0]||o1[w1[j][0]]))continue;
                if(!(vis1[j][3]||o2[w1[j][3]]))continue;
                ans++;//cout<<j<<"?"<<endl;
            }
            //cout<<i<<endl;
            //cout<<w2[i][0]<<" "<<w2[i][1]<<" "<<w2[i][2]<<" "<<w2[i][3]<<endl;
            cout<<ans<<endl;
        }
    //}
    return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
