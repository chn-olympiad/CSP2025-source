#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int n;
//pair<string,string> s[N];
map<string,string> s;

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        string s1,s2;
        //cin>>s[i].first>>s[i].second;
        cin>>s1>>s2;
        s[s1] = s2;
    }
    while(q--){
        pair<string,string> problem;
        cin>>problem.first>>problem.second;
        int ans = 0;
        for(int i=0;i<problem.first.length();i++){
            for(int j=1;j<problem.first.length()-i + 1;j++){
                string cut = problem.first.substr(i,j);
                if(s[cut] != ""){
                    string replaced = problem.first.substr(0,i) + s[cut] + problem.first.substr(i+j,problem.first.length()-(i+j));
                    if(replaced == problem.second){
                        ans++;
                    }
                }else{
                    s.erase(s[cut]);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
