/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull_t unsigned long long
int pre[5000005];
signed main(){
    pre[0]=1;
    for(int i=1;i<=5000000;i++) pre[i]=pre[i-1]*113;
    int n,q;
    cin>>n>>q;
    vector<pair<string,string> > s(q+1,make_pair("",""));
    vector<pair<string,string> > t(n+1,make_pair("",""));
    vector<pair<vector<ull_t>,vector<ull_t> > > hshs(q+1,make_pair(vector<ull_t>(),vector<ull_t>()));
    vector<pair<ull_t,ull_t> > hsht(n+1,make_pair(0,0));
    for(int i=1;i<=n;i++) cin>>t[i].first>>t[i].second;
    for(int i=1;i<=q;i++) cin>>s[i].first>>s[i].second;
    for(int i=1;i<=n;i++){
        ull_t now=0;
        for(int j=0;j<s[i].first.size();j++){
            now=now*113+((s[i].first)[j]-'a');
            hshs[i].first.push_back(now);
        }
        now=0;
        for(int j=0;j<s[i].second.size();j++){
            now=now*113+((s[i].second)[j]-'a');
            hshs[i].second.push_back(now);
        }
    }
    for(int i=1;i<=n;i++){
        ull_t now=0;
        for(int j=0;j<t[i].first.size();j++){
            now=now*113+((t[i].first)[j]-'a');
        }
        hsht[i].first=now;
        now=0;
        for(int j=0;j<t[i].second.size();j++){
            now=now*113+((t[i].second)[j]-'a');
        }
        hsht[i].second=now;
    }
    for(int i=1;i<=q;i++){
        int ans=0;
        int l=s[i].first.size();
        for(int k=0;k<l;k++){
            if(hshs[i].first[k]!=hshs[i].second[k]) continue;
            for(int j=1;j<=n;j++){
                int tmp=j+t[k].first.size();
                if(tmp>l) continue;
                if(tmp!=l&&
                    hshs[i].first[l]-hshs[i].first[tmp-1]*pre[n-tmp+1]!=
                    hshs[i].second[l]-hshs[i].second[tmp-1]*pre[n-tmp+1]
                ) continue;
                if(
                    hshs[i].first[tmp-1]-hshs[i].first[j-1]*pre[t[j].first.size()]!=
                    hsht[k].first) continue;
                if(
                    hshs[i].second[tmp-1]-hshs[i].second[j-1]*pre[t[j].second.size()]!=
                    hsht[k].second) continue;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull_t unsigned long long
int pre[5000005];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    vector<pair<string,string> > s(q+1,make_pair("",""));
    vector<pair<string,string> > t(n+1,make_pair("",""));
    for(int i=1;i<=n;i++) cin>>t[i].first>>t[i].second;
    for(int i=1;i<=q;i++) cin>>s[i].first>>s[i].second;
    for(int i=1;i<=q;i++){
        int ans=0;
        for(int j=0;j<s[i].first.size();j++){
            for(int k=1;k<=n;k++){
                if(j+t[k].first.size()-1>=s[i].first.size()) continue;
                string tmp=s[i].first;
                for(int l=0;l<t[k].first.size();l++){
                    tmp[j+l]=t[k].second[l];
                }
                if(tmp==s[i].second) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}