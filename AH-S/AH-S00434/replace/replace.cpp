#include <bits/stdc++.h>
#define int long long
#define gc getchar_unlocked
int read(){
    int x=0,f=0;char c=gc();
    while(!isdigit(c)){if(c=='-')f=1;c=gc();}
    while(isdigit(c))x=x*10+c-'0',c=gc();
    return f?-x:x;
}
using namespace std;
const int dd=2e6+5;
const int M=1e9+7;
int n,q;
vector<pair<string,string>>s;
int dp[dd];
vector<int>tai;
int idx[dd];
int pi[dd][2];
void getpi(string &s,bool ji){
    for(int i=1,j=0;i<s.size();i++){
        while(j>0&&s[i]!=s[j])j=pi[j-1][ji];
        j+=(s[i]==s[j]);pi[i][ji]=j;
    }
}
void KMP(string&s1,string&t1,string&s2,string&t2){
    if(s1.size()>t1.size())return;
    memset(pi,0,sizeof(pi));
    string f=s1+"#"+t1;
    string f2=s2+"#"+t2;
    getpi(f,0);getpi(f2,1);
    vector<int>plc;
    for(int i=0;i<f.size();i++){
        if(pi[i][0]==s1.size()&&pi[i][1]==s2.size()){
            tai.push_back(i-s1.size()-1);
        }
    }
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    n=read(),q=read();
    for(int i=1;i<=n;i++){
        string s1,s2;cin>>s1>>s2;
        s.push_back({s1,s2});
    }
    while(q--){
        string s1,s2;
        cin>>s1>>s2;int m=s1.size();
        memset(dp,0,sizeof(dp));dp[0]=1;
        memset(idx,0,sizeof(idx));
        for(int i=1;i<=m;i++){
            if(s1[i-1]!=s2[i-1])break;
            dp[i]=1;
        }
        for(int i=1;i<=n;i++){
            tai.clear();
            KMP(s[i-1].first,s1,s[i-1].second,s2);
            sort(tai.begin(),tai.end(),[](int a,int b){return a>b;});
            for(auto it:tai){
                dp[it+1]+=dp[it+1-s[i-1].first.size()];
                for(int k=it+2;k<=m;k++){
                    if(s1[k-1]!=s2[k-1])break;
                    dp[k]+=dp[it+1-s[i-1].first.size()];
                }
            }
        }
        printf("%lld\n",dp[m]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
