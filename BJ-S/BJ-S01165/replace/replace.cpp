#include<iostream>
#include<cstring>
#include<utility>
#include<map>
using namespace std;
const int maxn=202000,base=19260817,mod=998244353;
#define int long long
int n,q,ans;
string ss1,ss2,s1[maxn],s2[maxn];int bh[maxn],qian[maxn],hou[maxn],pw[5500000],has[maxn],hass[5500000];
map<pair<string,string>,int>mp;int cnt;
pair<string,string> mini(string xx,string yy,int pl){
    if(xx==yy)return {"",""};
    int zz1=0,zz2=xx.length()-1;
    while(xx[zz1]==yy[zz1])zz1++;
    while(xx[zz2]==yy[zz2])zz2--;
    qian[pl]=zz1;
    return {xx.substr(zz1,zz2-zz1+1),yy.substr(zz1,zz2-zz1+1)};
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    pw[0]=1;for(int i=1;i<=5100000;i++)pw[i]=pw[i-1]*base%mod;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];pair<string,string>ppp=mini(s1[i],s2[i],i);
        for(int j=0;j<=s1[i].length();j++)has[i]+=s1[i][j]*pw[j];has[i]%=mod;
        if(mp[ppp]<=0)mp[ppp]=++cnt;
        bh[i]=mp[ppp];
        //cout<<ppp.first<<" "<<bh[i]<<"\n";
    }
    while(q--){
        cin>>ss1>>ss2;ans=0;
        if(ss1.length()!=ss2.length()){
            cout<<"0\n";continue;
        }
        pair<string,string>ppp=mini(ss1,ss2,0);
        //cout<<ppp.first<<"\n";
        if(mp[ppp]<=0){
            cout<<"0\n";continue;
        }
        int kk=mp[ppp];
        for(int i=0;i<ss1.length();i++)hass[i]=(hass[i-1]+ss1[i]*pw[i])%mod;
        for(int i=1;i<=n;i++)if(bh[i]==kk){
            int st=qian[0]-qian[i];//cout<<st<<"\n";
            if((hass[st+s1[i].length()-1]+mod-(st==0?0:hass[st-1]))%mod==pw[st]*has[i]%mod)ans++;
            //cout<<ans<<"\n";
        }
        cout<<ans<<"\n";
    }
    return 0;
}