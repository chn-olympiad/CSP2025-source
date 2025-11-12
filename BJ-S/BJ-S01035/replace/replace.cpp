#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <map>
#define ll long long

#define ll long long

using namespace std;

map<pair<string,string>,vector<pair<string,string>>> mp;

inline bool few(string a,string b){
    if (a.size() == 0)return true;
    for (ll i = 0; i < a.size(); i++)if (*(a.rbegin()+i) != *(b.rbegin()+i)) return false;
    return true;
}

inline bool fsw(string a,string b){
    if (a.size() == 0)return true;
    for (ll i = 0; i < a.size(); i++)if (*(a.begin()+i) != *(b.begin()+i)) return false;
    return true;
}

int main()
{
    cin.tie(0);cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ll n,q;
    cin >> n >> q;
    for (ll i = 1; i<= n; i++){
        string t1,t2;
        cin >> t1 >> t2;
        bool flag = 1;
        ll stp=0,edp=t1.size()-1;
        for (ll i = 0; i <= t1.size(); i++){
            if (*(t1.begin()+i) != *(t2.begin()+i)){
                if (flag){
                    flag = 0;
                    stp = i;
                }
                edp = i;
            }
        }
        //cout << t1.size() << endl;
        //cout << stp << " " << edp << endl;
        //cout << t1.substr(stp,edp-stp+1)<<" "<<t2.substr(stp,edp-stp+1) <<" "<<
        //    t1.substr(0,stp)<<" "<<t1.substr(edp+1, t1.size()-edp) << endl;
         mp[make_pair(t1.substr(stp,edp-stp+1),t2.substr(stp,edp-stp+1))]
            .push_back(make_pair(t1.substr(0,stp),t1.substr(edp+1, t1.size()-edp)));
    }
    for (ll i = 1; i <= q; i++){
        string t1,t2;
        cin >> t1>>t2;
        bool flag = 1;
        ll stp=0,edp=t1.size()-1;
        for (ll i = 0; i <= t1.size(); i++){
            if (*(t1.begin()+i) != *(t2.begin()+i)){
                if (flag){
                    flag = 0;
                    stp = i;
                }
                edp = i;
            }
        }
        //cout << "aaa";
        ll ans = 0;
        string qz = t1.substr(0,stp),hz = t1.substr(edp+1, t1.size()-edp);
        vector<pair<string,string>> getss = mp[make_pair(t1.substr(stp,edp-stp+1),t2.substr(stp,edp-stp+1))];
        for (auto it : getss){
                if ((it.first.size() <= qz.size() && it.second.size() <= hz.size()) && i == 101){
                    //cout << it.first << endl<< it.second << endl <<qz << endl << hz <<endl <<
                    //fsw(it.first,qz) << few(it.second,hz)<< endl << endl;
                }
            //cout << it.first << " " << it.second << " " <<qz << " " << hz << endl;
            if ((it.first.size() <= qz.size() && it.second.size() <= hz.size()) &&
                (few(it.first,qz) && fsw(it.second,hz)))ans++;
        }
        cout << ans << endl;
    }
    return 0;
}