#include<bits/stdc++.h>
#define ull unsigned long long 
using namespace std;
const int kmaxn=2e5+10,kmaxm=5e6+10,Pr=131;
int n,q;
ull has[kmaxn],tr[26][2],U1=1;//每个位置对应的哈希值
string Ef[kmaxn][2];
struct node{
    int to[26];
    vector<int>A,B;//点的集合，询问的集合
}w[kmaxm];
int now=1,ans[kmaxn];
void add(string x,int ip){
    int u=1;
    for(char I:x){
        int i=I-'a';
        if(!w[u].to[i]){
            w[u].to[i]=++now;
        }
        u=w[u].to[i];
    }
    w[u].A.push_back(ip);
}
void Add(string x,int ip){
    int u=1;
    for(char I:x){
        int i=I-'a';
        if(!w[u].to[i]){
            w[u].B.push_back(ip);return ;
        }
        u=w[u].to[i];
    }
    w[u].B.push_back(ip);
    return ;
}
unordered_map<ull,int>DP;
void Sol(int x){
    for(int i:w[x].A)DP[has[i]]++;
    for(int i:w[x].B){
        int Pf=0;
        for(int j=0;j<Ef[i][0].size();j++)if(Ef[i][0][j]!=Ef[i][1][j])Pf=j;
        ull Has=0;
        for(int j=0;j<Ef[i][0].size();j++){
            Has=(Has*Pr+tr[Ef[i][0][j]-'a'][0]+tr[Ef[i][1][j]-'a'][1]);
            if(Pf<=j)ans[i]+=DP[Has];
        }
    }
    for(int j=0;j<26;j++){
        if(w[x].to[j])Sol(w[x].to[j]);
    }
    for(int i:w[x].A)DP[has[i]]--;
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);srand(time(0));
    for(int i=0;i<26;i++){
        for(int j=0;j<2;j++)tr[i][j]=U1*rand()*rand()*rand();
    }
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        int ed=-1;
        for(int j=0;j<s1.size();j++){
            if(s1[j]!=s2[j])ed=j;
        }
        if(ed<0)continue;
        for(int j=ed;j>=0;j--){
            has[i]=(has[i]*Pr+tr[s1[j]-'a'][0]+tr[s2[j]-'a'][1]);
        }
        string B="";
        for(int j=ed+1;j<s1.size();j++)B+=s1[j];
        add(B,i);
    }
    for(int i=1;i<=q;i++){
        string t1,t2;cin>>t1>>t2;
        int ed=-1;
        for(int j=0;j<t1.size();j++)if(t1[j]!=t2[j])ed=j;
        string T="";
        for(int j=ed+1;j<t1.size();j++)T+=t1[j];
        for(int j=ed;j>=0;j--){
            Ef[i][0]+=t1[j];
            Ef[i][1]+=t2[j];
        }
        Add(T,i);
    }
    Sol(1);
    for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
    return 0;
}