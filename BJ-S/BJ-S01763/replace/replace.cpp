#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
string s1[200005];
string s2[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin >> n>>q;
    for(int i = 1;i <= n;i ++){
        cin >> s1[i] >> s2[i];
    }
    while(q --){
        string t1,t2;
        int c = 0;
        cin >> t1 >> t2;
        int h = 0;
        for(int i = t1.size()-1;i >= 0;i --){
            if(t1[i] != t2[i]){
                h = i+1;
                break;
            }
        }
        bool g = 1;
        for(int i = 0;i < t1.size();i ++){
            for(int j = 1;j <= n;j ++){
                if(t1[i] == s1[j][0] and t2[i] == s2[j][0]){
                    bool f = 1;
                    for(int d = 1;d < s1[j].size();d ++){
                        if(t1[i+d] != s1[j][d])f = 0;
                        if(t2[i+d] != s2[j][d])f = 0;
                    }
                    if(f and i+s1[j].size() >= h)c++;
                }
            }
            if(t1[i] != t2[i])break;
        }
        cout << c << endl;
    }
    return 0;
}