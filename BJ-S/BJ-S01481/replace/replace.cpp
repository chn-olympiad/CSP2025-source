#include <cstdio>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const unsigned long long B=137;
string s1,s2;
map<pair<unsigned long long,unsigned long long>,int> mp;
vector<unsigned long long> g[200007];
vector<int> l[200007],t[200007];
unsigned long long h1[5000007],h2[5000007],pw[5000007];
int tot;
bool flag=false;
void chk(){
    int ca=0,cb=0;
    if(flag) return;
    int len=s1.length();
    for(int i=0;i<len;i++){
        if(s1[i]=='a') ca++;
        else if(s1[i]=='b') cb++;
        else{
            flag=true;
            return;
        }
    }
    if(cb!=1){
        flag=true;
        return;
    }
    ca=cb=0;
    for(int i=0;i<len;i++){
        if(s2[i]=='a') ca++;
        else if(s2[i]=='b') cb++;
        else{
            flag=true;
            return;
        }
    }
    if(cb!=1){
        flag=true;
        return;
    }
}
unsigned long long gethsh1(int l,int r){
    if(l>r) return 0;
    if(l==0) return h1[r];
    return h1[r]-h1[l-1]*pw[r-l+1];
}
unsigned long long gethsh2(int l,int r){
    if(l>r) return 0;
    if(l==0) return h2[r];
    return h2[r]-h2[l-1]*pw[r-l+1];
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    scanf("%d%d",&n,&q);
    pw[0]=1;
    for(int i=1;i<=5000000;i++) pw[i]=pw[i-1]*B;
    for(int i=1;i<=n;i++){
        cin>>s1;
        cin>>s2;
        chk();
        int len=s1.length(),idx=-1;
        for(int j=len-1;j>=0;j--){
            if(s1[j]!=s2[j]){
                idx=j;
                break;
            }
        }
        if(idx==-1) continue;
        unsigned long long hsh1=0;
        for(int j=0;j<=idx;j++){
            hsh1=hsh1*B+s1[j];
        }
        unsigned long long hsh2=0;
        for(int j=0;j<=idx;j++){
            hsh2=hsh2*B+s2[j];
        }
        unsigned long long ng=0;
        for(int j=idx+1;j<len;j++) ng=ng*B+s1[j];
        pair<unsigned long long,unsigned long long> x=make_pair(hsh1,hsh2);
        if(mp[x]==0) mp[x]=++tot;
        int id=mp[x];
        g[id].push_back(ng);
        l[id].push_back(len-idx-1);
        t[id].push_back(len-idx-1);
    }
    for(int i=1;i<=tot;i++) sort(t[i].begin(),t[i].end());
    int cc=0;
    while(q--){
        cc++;
        cin>>s1;
        cin>>s2;
        // if(cc==306) cerr<<s1<<" "<<s2<<endl;
        chk();
        int len=s1.length(),idx=-1;
        for(int j=len-1;j>=0;j--){
            if(s1[j]!=s2[j]){
                idx=j;
                break;
            }
        }
        h1[0]=s1[0];
        for(int i=1;i<len;i++) h1[i]=h1[i-1]*B+s1[i];
        h2[0]=s2[0];
        for(int i=1;i<len;i++) h2[i]=h2[i-1]*B+s2[i];
        int ans=0;
        for(int i=0;i<=idx;i++){
            unsigned long long hsh1=gethsh1(i,idx),hsh2=gethsh2(i,idx);
            if(mp.find(make_pair(hsh1,hsh2))!=mp.end()){
                int id=mp[make_pair(hsh1,hsh2)];
                if(!flag){
                    if(t[id][0]>len-idx-1) continue;
                    if(t[id][t[id].size()-1]<=len-idx-1) ans+=t[id].size();
                    else ans+=lower_bound(t[id].begin(),t[id].end(),len-idx-1)-t[id].begin();
                }else{
                    // if(cc==306) cerr<<i<<endl;
                    for(int j=0;j<g[id].size();j++){
                        if(idx+l[id][j]>=len) continue;
                        if(gethsh1(idx+1,idx+l[id][j])==g[id][j]){
                            ans++;
                        }
                    }
                }
            }
            if(s1[i]!=s2[i]) break;
        }
        printf("%d\n",ans);
        // if(cc==306) cerr<<ans<<endl;
    }
    return 0;
}
/*
zjojxhmkzosbfsrzoytcbjmouamvjtearyierexqrvbwtiuyucqryhrjmrrcmfastozgdyvnnejyokornvimwzaijuqsienpfofktwhydvztgxpavjrpsndwydcdsptolyoikshfbftmbyhqitcpgxvv
zjojxhmkzosbfsrzoytcbjmouamvjtearyierexqrvbwtinhvarpmcurogqsjnsymlzdmvilobyooplzkfvkhegxzrvcygauplfuyfkyakftyyxdsdswsndwydcdsptolyoikshfbftmbyhqitcpgxvv
*/