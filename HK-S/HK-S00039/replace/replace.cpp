#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, q;
vector<pair<string, string>> s;
string o1, o2, t1, t2;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin>>n>>q;
    //ll l1[n], r1[n], l2[n], r2[n];
    ll idk[n][2];
    vector<pair<pair<int, int>, pair<int, int>>> p;
    for(ll i=0; i<n; i++){
        cin>>o1>>o2;
        s.push_back({o1, o2});
        ll tmp1=o1.find('b'), tmp2=o2.find('b');
        //p.push_back({{1, 1}, {1, 1}});
        idk[i][0]=tmp1, idk[i][1]=tmp2;
        //p.push_back({{tmp1, o1.size()-tmp1-1}, {tmp2, o2.size()-tmp2-1}});
        //p[i].push_back({tmp2, o2.size()-tmp2-1});
    }
    sort(p.begin(), p.end());
    while(q--){
        cin>>t1>>t2;
        ll tmp1=t1.find('b'), tmp2=t2.find('b'), ans=0;
        ll l1=tmp1, r1=t1.size()-tmp1-1;
        ll l2=tmp2, r2=t2.size()-tmp2-1;
        //ll pl1=p.first.first, pr1=p.first.second;
        //ll pl2=p.second.first, pr2=p.second.second;
        for(ll i=0; i<n; i++){
                cout<<t1.find(s[i].first)<<" "<<t2.find(s[i].second)<<endl;
        //cout<<l2<<" "<<l1<<" "<<idk[i][1]<<" "<<idk[i][0]<<endl;
            if(t1.find(s[i].first)>5e6||t2.find(s[i].second)>5e6) continue;
            if(t1.find(s[i].first)==t2.find(s[i].second)&&t1.size()==s[i].first.size()) ans++;
            /*if(l2<=l1){
                if(pl1)
            }
            ans++;*/
        }
        cout<<ans<<endl;
    }
    return 0;
}

