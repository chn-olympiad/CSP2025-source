#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define fir first
#define sec second
#define base (13331ll)
#define mod1 (1000000007ll)
#define mod2 (1000000009ll)
#define mkp make_pair
using namespace std;
bool special(string s){
    int n=s.size();s=" "+s;
    int cnta=0,cntb=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='a')cnta++;
        if(s[i]=='b')cntb++;
    }
    return cntb==1&&cnta==n-1;
}
int n,q,lef[200005],rig[200005],cha[5000005],lp[5000005];
ll p1[5000005],p2[5000005],hsh1a[5000005],hsh2a[5000005],hsh1[5000005],hsh2[5000005];
//1,2：模数 a,b：变化规则前/后
string s1[200005],s2[200005];
vector<int>e[200005];
map<string,int>mp;
int tot;
pair<ll,ll>geta(int id,int l,int r){//id号的l到r
    l=rig[id-1]+l;
    r=rig[id-1]+r;
    //cout<<"geta "<<l<<","<<r<<"\n";
    //cout<<hsh1a[r]<<" "<<hsh1a[l-1]<<" "<<p1[r-l]<<" "<<hsh1a[l-1]*p1[r-l]%mod1<<"\n";
    return mkp(((hsh1a[r]-hsh1a[l-1]*p1[r-l+1]%mod1)+mod1)%mod1
               ,((hsh2a[r]-hsh2a[l-1]*p2[r-l+1]%mod2)+mod2)%mod2);
}
pair<ll,ll>get(int l,int r){//id号的l到r
    //cout<<"get "<<l<<","<<r<<"\n";
    return mkp(((hsh1[r]-hsh1[l-1]*p1[r-l+1]%mod1)+mod1)%mod1
               ,((hsh2[r]-hsh2[l-1]*p2[r-l+1]%mod2)+mod2)%mod2);
}
bool operator==(pair<ll,ll>x,pair<ll,ll>y){return x.fir==y.fir&&x.sec==y.sec;}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        lef[i]=rig[i-1]+1,rig[i]=lef[i]+s1[i].size()-1;
        for(int j=0;j<s1[i].size();j++)
            cha[lef[i]+j]=s1[i][j]-'a'+1;
        if(s1[i]==s2[i]){
            s1[i]=s2[i]="";
            continue;
        }
        int l=0,r=s1[i].size()-1;
        while(s1[i][l]==s2[i][l])l++;
        while(s1[i][r]==s2[i][r])r--;
        //cout<<s1[i].size()<<" "<<l<<"~"<<r<<" "<<r-l+1<<"\n";
        s1[i]=s1[i].substr(l,r-l+1);
        s2[i]=s2[i].substr(l,r-l+1);
        lp[i]=l;
        if(mp[s1[i]]==0)mp[s1[i]]=++tot,e[tot].pb(i);
        else e[mp[s1[i]]].pb(i);
        //cout<<s1[i]<<"->"<<s2[i]<<"\n";
    }
    p1[0]=p2[0]=1;
    for(int i=1;i<=5000000;i++)p1[i]=p1[i-1]*base%mod1,p2[i]=p2[i-1]*base%mod2;
    //cout<<p1[2]<<" !!";
    for(int i=1;i<=rig[n];i++){
        hsh1a[i]=(hsh1a[i-1]*base%mod1+cha[i])%mod1;
        hsh2a[i]=(hsh2a[i-1]*base%mod2+cha[i])%mod2;
            //cout<<cha[i]<<" "<<hsh1a[i]<<" !\n";
    }
    /*
    cout<<"\n";
    for(int i=1;i<=rig[n];i++)
            cout<<chb[i]<<" ";
    cout<<"\n";
    */


    //if(q==1||(q<=100000&&n<=100000)){
     //       cout<<"!";
        while(q--){

        string t1,t2;cin>>t1>>t2;
        if(t1.size()!=t2.size()){
            cout<<0<<"\n";
            continue;
        }
        int siz=t1.size();
        for(int i=1;i<=t1.size();i++){
            //cout<<t1[i-1]-'a'+1<<" ";
            hsh1[i]=(hsh1[i-1]*base%mod1+t1[i-1]-'a'+1)%mod1;
            hsh2[i]=(hsh2[i-1]*base%mod2+t1[i-1]-'a'+1)%mod2;
        }
        //cout<<"\n";
        int l=0,r=t1.size()-1;
        while(t1[l]==t2[l])l++;
        while(t1[r]==t2[r])r--;
        t1=t1.substr(l,r-l+1);
        t2=t2.substr(l,r-l+1);
        int res=0;
        //cout<<"t1="<<t1<<"\n";
        for(auto i:e[mp[t1]]){
       // for(int i=1;i<=n;i++){
            //cout<<"s1["<<i<<"]="<<s1[i]<<"\n";
          //  if(s1[i].size()!=t1.size())continue;
            //cout<<"1ok\n";
           // if(s1[i]!=t1)continue;
            if(s2[i]!=t2)continue;
            //cout<<"2ok\n";
            //cout<<lp[i]<<" "<<l<<" "<<rig[i]<<" "<<lef[i]<<"\n";
            if(l+1-lp[i]<1||l+1-lp[i]+(rig[i]-lef[i])>siz)continue;
            //cout<<"3ok\n";
            //cout<<geta(i,1,rig[i]-lef[i]+1).fir<<" "<<get(l+1-lp[i],l+1-lp[i]+(rig[i]-lef[i])).fir<<"\n";
            if(geta(i,1,rig[i]-lef[i]+1)==get(l+1-lp[i],l+1-lp[i]+(rig[i]-lef[i])))res++;//,cout<<"4ok\n";
        }
        cout<<res<<"\n";

        }
        return 0;
    //}

    return 0;
}
