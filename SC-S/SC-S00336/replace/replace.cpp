#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<cstring>
#include<cassert>
#include<algorithm>
using std::cin;
using std::cout;
#define db(x...) fprintf(stderr,x)
struct Code {
    Code() {
        freopen("replace.in","r",stdin);
        freopen("replace.out","w",stdout);
        std::ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
    }
    ~Code() {
        cout.flush();
        fclose(stdin);
        fclose(stdout);
    }
} code;
const int N=2e5+11;
int n,q;
std::vector<int> Q[N<<1];
std::map<std::pair<std::string,std::string>,int> mp;
int find(std::string s) {
    int l=s.length();
    int c[2]={0,0};
    for(int i=0;i<l;i++) {
        if(s[i]>'b') return -1;
        if(s[i]=='a') c[0]++;
        else c[1]=i;
    } 
    if(c[0]==l-1) return c[1];
    return -1;
}
int main() {
    cin>>n>>q;
    bool f=1;
    for(int i=1;i<=n;i++) {
        std::string s; cin>>s;
        std::string t; cin>>t;
        // int a=find(s),b=find(t);
        // if(a!=-1&&b!=-1) {
        //     Q[a-b+200000].push_back(a);
        // }
        mp[{s,t}]++;
        // else f=0;
    }
    // for(int i=0;i<=400000;i++)
    //     std::sort(Q[i].begin(),Q[i].end());
    // if(f) {
        while(q--) {
            std::string s; cin>>s;
            std::string t; cin>>t;
            if(s.length()!=t.length()) {
                cout<<"0\n";
                continue;
            }
            int n=s.length();
            int p=0,q=0;
            for(int i=0;i<n;i++)
                if(s[i]!=t[i]) {
                    p=i;
                    break;
                }
            for(int j=n-1;j>=0;j--)
                if(s[j]!=t[j]) {
                    q=j;
                    break;
                }
            int ans=0;
            for(int i=0;i<=p;i++) {
                std::string s1="",t1="";
                for(int j=i;j<q;j++) s1+=s[j],t1+=t[j];
                for(int j=q;j<n;j++) {
                    s1+=s[j],t1+=t[j];
                    // db("%s %s\n",s1.data(),t1.data());
                    ans+=mp[{s1,t1}];
                }

            }
            cout<<ans<<'\n';
            // int a=find(s),b=find(t);
            // int x=a-b+200000;
            // cout<<(std::upper_bound(Q[x].begin(),Q[x].end(),a)-std::lower_bound(Q[x].begin(),Q[x].end(),s.length()))<<'\n';
        }
    // }
    return 0;
}