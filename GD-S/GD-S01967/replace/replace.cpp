#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10000005;
vector<pair<string,string> >a;
ll n,q,ans;
string my_replace(string t1,string s1,string s2){
    auto bi=find(t1.begin(),t1.end(),s1);
    ll b=bi-t1.begin();
    string ans;
    copy(t1.begin(),t1.begin()+b,ans);
    copy(bi,bi+s1.size(),ans.end());
    copy(t1.begin()+s1.size(),t1.end(),ans.end());
    return ans;
}
int main(){
	freopen("replace1.in","r",stdin);
    //freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>q;
    string s1,s2,s3;
    for(ll i=1;i<=n;++i){
        cin>>s1>>s2;
        a.push_back(make_pair(s1,s2));
    }
    string t1,t2,t3;
    while(q--){
        cin>>t1>>t2;
        for(auto to:a){
            s1=to.first,s2=to.second;
            //t3=my_replace(t1,s1,s2);
            ll i;
            for(i=0;i<t3.size();++i){
                //if(t3[i]!=t2[i])break;
            }
            //if(i!=t3.end()-t3.begin())++ans;
        }
    }
    cout<<ans;
    return 0;
}
