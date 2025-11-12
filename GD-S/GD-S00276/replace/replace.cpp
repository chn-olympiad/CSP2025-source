#include <bits/stdc++.h>
using namespace std;

const int N=2*1e5;
long long n,q,ans;
string t1,t2;

struct Node{
    string s1,s2;
}s[N+5];

int check(int x, int z){
    string y;
    for(int i=x; i<t1.size()-z; i++){
        y+=t1[i];
    }
    string Y;
    for(int i=1; i<=n; i++){
        if(y==s[i].s1){
            Y=s[i].s2;
        }
    }
    string X,Z;
    for(int i=0; i<=t1.size()-y.size()-z; i++){
        X+=t1[i];
    }
    for(int i=x+y.size()-1; i<=t1.size(); i++){
        Z+=t1[i];
    }
    if(X+Y+Z==t2){
        ans++;
    }
    check(x+1, z);
    check(x, z+1);
    check(x+1, z+1);
    return ans;
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> s[i].s1 >> s[i].s2;
    }
    while(q--){
        ans=0;
        cin >> t1 >> t2;
        cout << check(0, 0);
    }
    return 0;
}
