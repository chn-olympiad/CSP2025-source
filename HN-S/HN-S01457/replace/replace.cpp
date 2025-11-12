#include<bits/stdc++.h>
using namespace std;
int n,q;
const int N=2e5,M=5e6;
int maxsons;
string ccf[N+5],ccts[N+5];
int id[N+5];
struct ACauto{
    int cnt;
    vector<int> fail,val;
    vector<vector<int> > sons;
    int head;
    vector<int> que;
    void init(){
        fail.emplace_back(0);
        val.emplace_back(0);
        vector<int> tmp;
        for(int i=1;i<=maxsons;i++) tmp.emplace_back(0);
        sons.emplace_back(tmp);
        cnt=1;
    }
    void insert(string str){
        int pos=0;
        for(int i=0;i<str.size();i++){
            int v=str[i]-'a';
            if(!sons[pos][v]){
                sons[pos][v]=cnt++;
                fail.emplace_back(0);
                val.emplace_back(0);
                vector<int> tmp;
                for(int i=1;i<=maxsons;i++) tmp.emplace_back(0);
                sons.emplace_back(tmp);
            }
            pos=sons[pos][v];
        }
        val[pos]++;
    }
    void build(){
        head=0;
        for(int i=0;i<maxsons;i++){
            if(sons[0][i]){
                que.emplace_back(sons[0][i]);
                fail[sons[0][i]]=0;
            }
        }
        while(head<=que.size()){
            int u=que[head++];
            for(int i=0;i<maxsons;i++){
                if(sons[u][i]){
                    fail[sons[u][i]]=sons[fail[u]][i];
                    que.emplace_back(sons[u][i]);
                }
                else{
                    sons[u][i]=sons[fail[u]][i];
                }
            }
        }
        for(int i=que.size()-1;i>=0;i--){
            val[fail[que[i]]]+=val[que[i]];
        }
    }
    int query(string str){
        int pos=0;
        int ans=0;
        for(int i=0;i<str.size();i++){
            ans+=val[pos];
            pos=sons[pos][str[i]-'a'];
        }
        return ans;
    }
} AC[N+5];
const int hashmod[2]={998244353,1000000007};
int cnt;
mt19937 rnd(time(0));
int base=rnd()%201+65536;
map<pair<int,int>,int> mp;
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    maxsons=27;
    for(int j=1;j<=n;j++){
        string str1,str2;
        cin>>str1>>str2;
        if(str1==str2) continue;
        int pre=str1.size();
        for(int i=0;i<str1.size();i++){
            if(str1[i]!=str2[i]){
                pre=i;
                break;
            }
        }
        int suf=0;
        for(int i=str1.size()-1;i>=0;i--){
            if(str1[i]!=str2[i]){
                suf=i;
                break;
            }
        }
        pair<int,int> res={0,0};
        for(int i=pre;i<=suf;i++){
            res.first=((long long)res.first*base+(str1[i]-'a'+1)*27+(str2[i]-'a'+1))%hashmod[0];
            res.second=((long long)res.second*base+(str1[i]-'a'+1)*27+(str2[i]-'a'+1))%hashmod[1];
        }
        if(mp.count(res)){
            mp[res]=++cnt;
        }
        id[j]=mp[res];
        string cis="";
        for(int i=0;i<pre;i++){
            cis=cis+str1[i];
            maxsons=max(maxsons,str1[i]-'a'+1);
        }
        ccf[j]=cis;
        cis="";
        //cis=cis+(char)('z'+1);
        for(int i=suf+1;i<str1.size();i++){
            cis=cis+str1[i];
            maxsons=max(maxsons,str1[i]-'a'+1);
        }
        //cout<<cis<<"\n";
        ccts[j]=cis;
    }
    maxsons++;
    for(int i=1;i<=cnt;i++){
        AC[i].init();
    }
    for(int i=1;i<=n;i++){
        ccf[i]=ccf[i]+((char)('a'+maxsons-1))+ccts[i];
        AC[id[i]].insert(ccf[i]);
    }
    for(int i=1;i<=cnt;i++){
        AC[i].build();
    }
    for(int j=1;j<=q;j++){
        string str1,str2;
        cin>>str1>>str2;
        int pre=str1.size();
        for(int i=0;i<str1.size();i++){
            if(str1[i]!=str2[i]){
                pre=i;
                break;
            }
        }
        int suf=0;
        for(int i=str1.size()-1;i>=0;i--){
            if(str1[i]!=str2[i]){
                suf=i;
                break;
            }
        }
        pair<int,int> res={0,0};
        for(int i=pre;i<=suf;i++){
            res.first=((long long)res.first*base+(str1[i]-'a'+1)*27+(str2[i]-'a'+1))%hashmod[0];
            res.second=((long long)res.second*base+(str1[i]-'a'+1)*27+(str2[i]-'a'+1))%hashmod[1];
        }
        if(!mp.count(res)) cout<<"0\n";
        int idt=mp[res];
        string cis;
        for(int i=pre;i<=suf;i++){
            res.first=((long long)res.first*base+(str1[i]-'a'+1)*27+(str2[i]-'a'+1))%hashmod[0];
            res.second=((long long)res.second*base+(str1[i]-'a'+1)*27+(str2[i]-'a'+1))%hashmod[1];
        }
        if(mp.count(res)){
            mp[res]=++cnt;
        }
        id[j]=mp[res];
        string ciss="";
        for(int i=0;i<pre;i++){
            ciss=ciss+str1[i];
        }
        for(int i=suf+1;i<str1.size();i++){
            ciss=ciss+str1[i];
        }
        cout<<AC[idt].query(ciss)<<"\n";
    }
    return 0;
}
