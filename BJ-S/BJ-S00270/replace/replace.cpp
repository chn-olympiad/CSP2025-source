#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,cnt;
pair<string,string>st[200001],st1[200001];
string stt;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for (ll i=1;i<=n;i++) cin>>st[i].first>>st[i].second;
    for (ll i=1;i<=q;i++) cin>>st1[i].first>>st1[i].second;
    if (q<=1000 || n<=1000){
        for (ll i=1;i<=q;i++){
            if (st1[i].first.size()!=st1[i].second.size()){
                cout<<"0\n";
                continue;
            }
            cnt=0;
            for (ll j=1;j<=n;j++){
                stt="";
                if (st1[i].first.find(st[j].first)!=string::npos){
                    ll pos=st1[i].first.find(st[j].first);
                    ll pos2=pos+st[j].second.size();
                    for (ll k=0;k<pos;k++) stt+=st1[i].first[k];
                    stt+=st[j].second;
                    for (ll k=pos2;k<st1[i].first.size();k++) stt+=st1[i].first[k];
                }
                if (stt==st1[i].second) cnt++;
            }
            cout<<cnt<<'\n';
        }
        return 0;
    }
    return 0;
}
