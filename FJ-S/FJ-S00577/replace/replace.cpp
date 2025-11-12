#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
using ll=unsigned long long;
const ll N=1e5+10,M=1e4+10,p1=13331,p2=998244353;
map<pair<ll,ll>,int> vis;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        string s1,s2;
        cin>>s1>>s2;
        ll sum1=0,sum2=0;
        for(int i=0;i<s1.length();++i)sum1=sum1*p1+(s1[i]-'a')*26+s2[i]-'a';
        for(int i=0;i<s1.length();++i)sum2=sum2*p2+(s1[i]-'a')*26+s2[i]-'a';
        ++vis[{sum1,sum2}];
    }
    for(int i=1;i<=q;++i){
        string s1,s2;
        cin>>s1>>s2;
        if(s1.length()!=s2.length()){
            puts("0");
            continue;
        }
        int ans=0;
        for(int l=0;l<s1.length();++l){
            ll sum1=0,sum2=0;
            if(l&&s1[l-1]!=s2[l-1])break;
            for(int i=l;i<s1.length();++i){
                sum1=sum1*p1+(s1[i]-'a')*26+s2[i]-'a';
                sum2=sum2*p2+(s1[i]-'a')*26+s2[i]-'a';
                if(i==s1.length()-1||s1[i+1]==s2[i+1])ans+=vis[{sum1,sum2}];
            }
        }
        printf("%d\n",ans);
    }
}