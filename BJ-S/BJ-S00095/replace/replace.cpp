#include <bits/stdc++.h>
using namespace std;
typedef pair<string,string> pss;
const int N = 2e5+5;
pair<pss,pair<int,int> > s[N];
pss t[N];
pss ds[N];
pair<int,int> diff(string a,string b){
    int L=0,R=a.size()-1;
    while(L<a.size()&&a[L]==b[L])L++;
    while(R>L&&a[R]==b[R])R--;
    return {L,R};
}
bool cmp(pair<pss,pair<int,int> > a,pair<pss,pair<int,int> > b){
    pss str1={a.first.first.substr(a.second.first,a.second.second-a.second.first+1),a.first.second.substr(a.second.first,a.second.second-a.second.first+1)};
    pss str2={b.first.first.substr(b.second.first,b.second.second-b.second.first+1),b.first.second.substr(b.second.first,b.second.second-b.second.first+1)};
    return ((str1!=str2)?(str1<str2):(a.first.first.size()<b.first.first.size()));
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i =1;i<=n;i++){
        cin>>s[i].first.first>>s[i].first.second;
        s[i].second=diff(s[i].first.first,s[i].first.second);
    }
    sort(s+1,s+n+1,cmp);
    for(int i = 1;i<=n;i++){
        ds[i]={s[i].first.first.substr(s[i].second.first,s[i].second.second-s[i].second.first+1),s[i].first.second.substr(s[i].second.first,s[i].second.second-s[i].second.first+1)};
    }

    for(int i = 1;i<=q;i++){
        cin>>t[i].first>>t[i].second;
        pair<int,int> st=diff(t[i].first,t[i].second);
        pss dt;
        dt={t[i].first.substr(st.first,st.second-st.first+1),t[i].second.substr(st.first,st.second-st.first+1)};
        if(binary_search(ds+1,ds+n+1,dt)){
            int ans=0;
            int L=lower_bound(ds+1,ds+n+1,dt)-ds;
            int R=upper_bound(ds+1,ds+n+1,dt)-ds;
            for(int j = L;j<R;j++){
                if(st.first-s[j].second.first>=0){
                    pss str1={t[i].first.substr(st.first-s[j].second.first,s[j].first.first.size()),t[i].second.substr(st.first-s[j].second.first,s[j].first.first.size())};
                    pss str2=s[j].first;
                    if(str1==str2){
                        ans++;
                    }
                }
            }
            cout<<ans<<endl;
        }else{
            cout<<0<<endl;
        }
    }
}
