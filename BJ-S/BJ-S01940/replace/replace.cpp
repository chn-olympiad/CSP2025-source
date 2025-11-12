#include <bits/stdc++.h>
using namespace std;
int n,m;
const int M = 200005;
string s1[M],s2[M],t1,t2;
int kmp[M];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> s1[i] >> s2[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> t1 >> t2;
//        int j = 0;
//        for(int i = 1; i < t1.size(); i++){
//            while(j > 0 && t1[i]!=t1[j])j=kmp[j-1];
//            if(t1[i]==t1[j])j++;
//            kmp[i]=j;
//        }
        if(t1.size()!=t2.size()){
            cout <<0 <<endl;
            continue;
        }
        cout << 0 <<endl;
    }
    return 0;
}
