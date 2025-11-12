#include<bits/stdc++.h>
#define int long long
#define mk make_pair
using namespace std;
const int N=2e5+10,bas=1311;
int n,q,pre[N],surf[N],tot;
unsigned int hsh[N],hhh[N*25],po[N*25];
string s[N][3],ss,sss,t[3],kkk;
map<pair<string,string>,int>mp;
vector<int>v[N];
int check(int x,int fl){
    // cout<<x<<' '<<fl<<'\n';
    if(pre[x]>fl) return 0;
    if(s[x][1].size()-pre[x]>t[1].size()-fl) return 0;
    // if(fl-pre[x]!=0){
        // cout<<hsh[x]*po[fl-pre[x]]<<' '<<hhh[fl-pre[x]+s[x][1].size()-1]-hhh[fl-pre[x]-1]*po[s[x][1].size()]<<'\n';
        // cout<<fl-pre[x]+s[x][1].size()-1<<' '<<fl-pre[x]<<' '<<s[x][1].size()<<'\n';
    // }
    // else cout<<hsh[x]<<' '<<hhh[s[x][1].size()-1]<<'\n';
    if(fl-pre[x]!=0&&hsh[x]==hhh[fl-pre[x]+s[x][1].size()-1]-hhh[fl-pre[x]-1]*po[s[x][1].size()]) return 1;
    else if(fl-pre[x]==0){
        if(hsh[x]==hhh[s[x][1].size()-1])
            return 1;
    }
    return 0;
    for(int i=fl-pre[x];i<fl-pre[x]+s[x][1].size();i++){
        if(i==fl-pre[x])
           kkk=t[1][i];
        else kkk+=t[1][i];
    }
    // cout<<kkk<<' '<<s[x][1]<<'\n';
    if(kkk==s[x][1]) return 1;
    return 0;
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    po[0]=1;
    for(int i=1;i<=5000000;i++)
        po[i]=po[i-1]*bas;
    for(int i=1;i<=n;i++){
        sss=" ";
        ss=" ";
        cin>>s[i][1]>>s[i][2];
        pre[i]=-1;
        for(int j=0;j<s[i][1].size();j++){
            // cout<<s[i][1][j]<<' '<<s[i][2][j]<<'\n';
            if(s[i][1][j]!=s[i][2][j]){
                if(pre[i]==-1) pre[i]=j;
                surf[i]=j;
            }
        }
        if(pre[i]!=-1){
            for(int j=pre[i];j<=surf[i];j++)
                ss+=s[i][1][j],sss+=s[i][2][j];
        }
        // cout<<pre[i]<<'\n';
        // cout<<ss<<' '<<sss<<'\n';
        if(mp[mk(ss,sss)]==0){
            tot++;
            mp[mk(ss,sss)]=tot;
            v[tot].push_back(i);
        }
        else
            v[mp[mk(ss,sss)]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<s[i][1].size();j++){
            hsh[i]+=(unsigned int)(s[i][1][j]-'a'+1);
            if(j+1!=s[i][1].size())
                hsh[i]*=bas;
        }
    }
    // cout<<'\n';
    while(q--){
        int fl=-1,sf=0;
        ss=" ",sss=" ";
        cin>>t[1]>>t[2];
        for(int i=0;i<t[1].size();i++){
            if(t[1][i]!=t[2][i]){
                if(fl==-1) fl=i;
                sf=i;
            }
        }
        if(fl!=-1){
            for(int i=fl;i<=sf;i++)
                ss+=t[1][i],sss+=t[2][i];
        }
        // cout<<ss<<' '<<sss<<'\n';
        for(int i=0;i<t[1].size();i++){
            hhh[i]=(unsigned int)(t[1][i]-'a'+1);
            if(i!=0)
                hhh[i]+=hhh[i-1]*bas;
        }
        int op=mp[mk(ss,sss)];
        if(op==0)
            cout<<0<<'\n';
        else{
            int ans=0;
            for(int i:v[op])
                ans+=check(i,fl);
            cout<<ans<<'\n';
        }
    }
    return 0;
}