#include <bits/stdc++.h>
using namespace std;
ifstream in("replace.in");
ofstream out("replace.out");
int main(){
    int n,q;
    in>>n>>q;

    vector<pair<string ,string>> s(n);
    int l1=0,l2=0;
    for(int i=0;i<n;i++){
        in>>s[i].first>>s[i].second;
        l1+=s[i].first.length()+s[i].second.length();
    }

    
    vector<pair<string ,string>> t(q);
    for(int i=0;i<q;i++){
        in>>t[i].first>>t[i].second;
        l2+=t[i].first.length()+t[i].second.length();
    }

    if(1){
        for(int z=0;z<q;z++){
            string t1=t[z].first;
            string t2=t[z].second;

            int ans=0;
            for(int i=0;i<n;i++){
                string s1=s[i].first, s2=s[i].second;

                int sl=s[i].first.length();
                if(sl>t1.length()) continue;

                string hi="";
                string pref="";
                string surf="";
                for(int j=0;j<sl;j++)   hi+=t1[j];
                for(int j=sl;j<t1.length();j++)   surf+=t1[j];

                if(hi==s1){
                    string tmp=pref;
                    tmp+=s2;
                    tmp+=surf;
                    if(tmp==t2)    ans++;
                }


                for(int j=sl;j<t1.length();j++){
                    pref+=t1[j-sl];

                    hi+=t1[j];
                    hi.erase(hi.begin());
                    surf.erase(surf.begin());

                    
                    if(hi==s1){
                        string tmp=pref;
                        tmp+=s2;
                        tmp+=surf;
                        if(tmp==t2)    ans++;
                    }
                }
            }
            out<<ans<<'\n';
        }
    }

    return 0;
}