#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N=200010;


int n,q;
string s[N][2];
string dist;

int dfs(string f){
    int lf = f.length();
    int ans=0;
    for(int x=0;x<lf;x++){// for "the begin point"
        for(int y=0;y<n;y++){// for "the rules"
            int ly = s[y][0].length();
            if(lf-y>=ly){
                if(f.substr(x,ly)==s[y][0]){
                    string ns=f;
                    for(int z=0;z<ly;z++)ns[x+z]=s[y][1][z];

                    if(ns==dist){
                        ans++;
                        //cout<<"Way "<<ans<<": replace \""<<s[y][0]<<"\" at "<<x<<" to \""<<s[y][1]<<"\" [rule"<<y<<"]"<<endl;
                    }
                }
            }
        }
    }
    return ans;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    cin>>n>>q;
    for(int x=0;x<n;x++){
        cin>>s[x][0]>>s[x][1];
    }
    for(int x=0;x<q;x++){
        string f;
        cin>>f>>dist;
        cout<<dfs(f)<<endl;
    }

    return 0;
}