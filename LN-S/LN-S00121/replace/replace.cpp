#include<bits/stdc++.h>
//#define debug
using namespace std;
const int N=1e5+10;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q,tot=0;
    cin>>n>>q;
    pair<string,string> x[n+9];
    for(int i=0;i<n;i++) cin>>x[i].first>>x[i].second;
    while(q--){
        string s1,s2;
        cin>>s1>>s2;/////////////////////////
        int t;
        for(int i=0;i<s1.size();i++){
            for(int j=0;j<n;j++){
                if(s1[i]==x[j].first[i]){
                        #ifdef debug
                        cout<<"[Debug] s1[i] '"<<s1[i]<<"' == x[j].first[i] '"<<x[j].first[i]<<"'\n[Debug] t=i ("<<i<<")\n";
                        #endif // debug
                    t=i;
                    bool flag=0;
                    if(s1.size()-i<x[j].first.size()) continue;
                    for(int k=t;k<=x[j].first.size();k++){
                        if(s1[k]!=x[j].first[k]){
                                #ifdef debug
                                cout<<"[Debug] s1[k] '"<<s1[k]<<"' != x[j].first[k] '"<<x[j].first[k]<<"'\n[Debug] Exit range.\n";
                                #endif // debug
                            flag=1;break;
                        }
                    }
                    if(flag) continue;
                    for(int k=t;k<x[j].first.size();k++){
                        if(s2[k]!=x[j].second[k]){
                                #ifdef debug
                                cout<<"[Debug] s2[k] '"<<s2[k]<<"' != x[j].first[k] '"<<x[j].first[k]<<"'\n[Debug] Exit range.\n";
                                #endif // debug
                            flag=1;break;
                        }
                    }
                    if(flag) continue;
                    tot++;
                    #ifdef debug
                    cout<<"[Debug] tot++(now = "<<tot<<")\n";
                    #endif // debug
                }
            }
        }
        cout<<tot<<endl;
        #ifdef debug
        cout<<"[Debug] Cleared tot.\n[Debug] ----------------\n";
        #endif // debug
        tot=0;
    }
    return 0;
}
