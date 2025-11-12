#include <bits/stdc++.h>
using namespace std;
const int N=5e6+5;
int n,q,tr[N][26],cnt=1,fail[N],ok[N],len[N],dep[N],lb[N],dp[N];
void insert(string s){
    int x=1;
    for(char c:s){
        int k=len[x];
        if(tr[x][c-'a']) x=tr[x][c-'a'];
        else x=tr[x][c-'a']=++cnt;
        len[x]=k+1;
    }
    ok[x]++;
}
void getfail(){
    queue<int>q;
    while(!q.empty()) q.pop();
    fail[1]=1;
    for(int c=0;c<26;c++){
        if(tr[1][c]) fail[tr[1][c]]=1,q.push(tr[1][c]);
        else tr[1][c]=1;
    }
    dp[1]=0;
    lb[1]=1;
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(int c=0;c<26;c++){
            if(tr[x][c]) fail[tr[x][c]]=tr[fail[x]][c],q.push(tr[x][c]);
            else tr[x][c]=tr[fail[x]][c];
        }
        dep[x]=dep[fail[x]]+ok[x];
        dp[x]=dp[fail[x]]+1;
        if(dp[fail[x]]-dp[lb[fail[x]]]==dp[lb[fail[x]]]-dp[lb[lb[fail[x]]]]) lb[x]=lb[lb[fail[x]]];
        else lb[x]=fail[x];
    }
}
int jmp(int x,int k){
    if(len[x]<k) return 0;
    int t=x;
    while(len[t]>=k){
        if(len[lb[t]]>=k) t=lb[t];
        else t=fail[t];    
    }
    return dep[x]-dep[t];
}
int answ(string s,int a,int b){
    int x=1,ans=0;
    for(int i=0;i<s.size();i++){
        x=tr[x][s[i]-'a'];
        if(i>=b&&(i&1)) ans+=jmp(x,i-a+1);
    }
    return ans;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s1,s2,s="";
        cin>>s1>>s2;
        for(int j=0;j<s1.size();j++) s+=s1[j],s+=s2[j];
        insert(s);
    }
    getfail();
    for(int i=1;i<=q;i++){
        string s1,s2,s="";
        int a=s1.size(),b=-1;
        cin>>s1>>s2;
        for(int j=0;j<s1.size();j++) s+=s1[j],s+=s2[j];
        for(int j=0;j<s1.size();j++){
            if(s1[j]!=s2[j]){
                a=j;
                break;
            }
        }
        for(int j=s1.size()-1;~j;j--){
            if(s1[j]!=s2[j]){
                b=j;
                break;
            }
        }
        cout<<answ(s,a*2,b*2+1)<<"\n";
    }
    return 0;
}