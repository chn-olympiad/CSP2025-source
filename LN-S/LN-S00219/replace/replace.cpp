#include <bits/stdc++.h>
using namespace std;
int n,q;
vector<pair<string,string> > s;
vector<pair<string,string> > t;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i=0;i<n;i++){
        string s1;
        string s2;
        cin >> s1 >> s2;
        s.push_back(make_pair(s1,s2));
    }
    for(int i=0;i<q;i++){
        string t1;
        string t2;
        cin >> t1 >> t2;
        t.push_back(make_pair(t1,t2));
    }
    for(int i=0;i<t.size();i++){
        string t1 = t[i].first;
        string t2 = t[i].second;
        int cnt = 0;
        bool only1 = false;
        if(t1.size()!=t2.size()){
            cout << 0 << endl;
            continue;
        }
        /*for(int j=0;j<t1.size();j++){
            if(t1[j]!=t2[j] && only1 == true){
                cout << 0 << endl;
                continue;
            }else if(t1[j]==t2[j] && t1[j-1]!=t2[j-1] && j!=0){
                only1 = true;
            }
        }*/
        for(int j=0;j<n;j++){
            bool only2 = false;
            string s2 = s[j].second;
            string s1 = s[j].first;
            int t2s = t2.size();
            int s2s = s2.size();
            //cout << t2s - s2s<<endl;
            if(t2s-s2s<0){
                continue;
            }
            for(int k=0;k<=t2s-s2s;k++){
                    //cout << "I Entered" << endl;
                if(t2.substr(k,s2.size()) == s2){//可能会错
                    if(t1.substr(k,s2.size()) == s1){
                        if(only2 == false){
                            cnt++;
                            only2 = true;
                        }else{
                            cnt--;
                        }
                        //cout << s2 << endl;
                    }
                }
            }
        }
        if(cnt<0){
            cnt=0;
        }
        cout << cnt << endl;
    }
    return 0;
}
