#include <bits/stdc++.h>
using namespace std;

string f[200005][2],g,h;
int n,q,ss = 5*1000000;

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i = 0;i<n;i++)cin >> f[i][0] >> f[i][1];
    for(int i = 0;i<q;i++){
        cin >> g >> h;
        string l = g;
        int s = 0;
        for(int j = 0;j<n;j++){
            int k = 0;
            if(g.find(f[j][0])<ss && g.find(f[j][0])==h.find(f[j][1])){
                for(int k = g.find(f[j][0]);k<g.find(f[j][0])+f[j][0].size();k++){
                    l[k] = f[j][0][k];
                }if(l==h)s++;
            }
        }cout << s << endl;
    }
      
    return 0;
}