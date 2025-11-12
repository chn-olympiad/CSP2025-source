#include <bits/stdc++.h>
using namespace std;

struct p{
    string a,b;
};

string replace(string a,string b,int start){
    for (int i = start;i < start+b.size();i ++){
        a[i] = b[i-start];
    }
    return a;
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin.tie(0);cout.tie(0);
    int n,q;
    cin >> n >> q;
    vector<p> ss;
    for (int i = 0;i < n;i ++){
        p tmp;
        cin >> tmp.a >> tmp.b;
        ss.push_back(tmp);
    }
    while (q --){
        string a,b;
        int ans = 0;
        cin >> a >> b;
        for (int i = 0;i < n;i ++){
            if (a.find(ss[i].a) >= 0){
                if(replace(a,ss[i].b,a.find(ss[i].a)) == b){
                    ans ++;continue;
                }
            }
            if (a == ss[i].a && ss[i].b == b) ans ++;
        }
        cout << ans << endl;
    }
    return 0;
}