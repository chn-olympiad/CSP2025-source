#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
const int N=2e5+5,L=5e6+6;
int n,q,pi[L],pi2[L],dif[N];
string s1[N],s2[N],t1,t2;
int main(){
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        for(int j=0;j<s1[i].size();j++){
            if(s1[i][j]!=s2[i][j])dif[i]++;
        }
    }
    while(q--){
        cin>>t1>>t2;
        int ans=0,cnt=0;
        for(int i=0;i<t1.size();i++){
            if(t1[i]!=t2[i])cnt++;
        }
        for(int x=1;x<=n;x++){
            if(cnt!=dif[x])continue;
            set<int>pos;
            string ss=" "+s1[x]+"*"+t1;
            int m=ss.size()-1;
            for(int i=1;i<=m;i++)pi[i]=0;
            for(int i=2;i<=m;i++){
                int j=pi[i-1];
                while(j&&ss[j+1]!=ss[i])j=pi[j];
                if(ss[j+1]==ss[i])j++;
                pi[i]=j;
                if(pi[i]==s1[x].size())pos.insert(i);
            }
            string st=" "+s2[x]+"*"+t2;
            int m2=st.size()-1;
            for(int i=1;i<=m;i++)pi2[i]=0;
            for(int i=2;i<=m2;i++){
                int j=pi2[i-1];
                while(j&&st[j+1]!=st[i])j=pi2[j];
                if(st[j+1]==st[i])j++;
                pi2[i]=j;
                if(pi2[i]==s2[x].size()&&pos.count(i))ans++;
            }

        }
        cout<<ans<<"\n";
    }
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