#include <bits/stdc++.h>
using namespace std;
int n,q,ee,e;
map<string,int> mp;
vector <string> ve[200010];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        if(!mp[s1]){
            ee++;
            mp[s1]=ee;
            e=ee;
        }
        else e=mp[s1];
        ve[e].push_back(s2);
    }
    while(q--){
        int cnt=0;
        string s1,s2;
        cin>>s1>>s2;
        for(int i=0;i<s1.size();i++){
            for(int j=i;j<s1.size();j++){
                int ok=1;
                for(int w=0;w<i;w++){
                    if(s1[w]!=s2[w]){
                        ok=0;
                        break;
                    }
                }
                for(int w=j+1;w<s1.size();w++){
                    if(s1[w]!=s2[w]){
                        ok=0;
                        break;
                    }
                }
                if(!ok) continue;
                string t1="",t2="";
                for(int w=i;w<=j;w++){
                    t1+=s1[w],t2+=s2[w];
                }
                if(mp[t1]){
                    int w=mp[t1];
                    for(int d=0;d<ve[w].size();d++){
                        if(ve[w][d]==t2){
                            cnt++;
                            break;
                        }
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
