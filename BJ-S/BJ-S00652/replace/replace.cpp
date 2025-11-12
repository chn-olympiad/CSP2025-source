#include <bits/stdc++.h>

using namespace std;
const int N = 2e5+5, L=5e6;
const string E = " ";
int nxt[L];
int n, q;
string s1[N], s2[N];

void getnxt(string t){
//    t=E+t;
    nxt[0]=-1;
    for (int i=1; i<t.size(); i++){
        int j=nxt[i-1];
        while (j>=0&&t[i]!=t[j+1]) j=nxt[j];
        if (t[i]==t[j+1]) j++;
        nxt[i] = j;
    }
}

vector<int> kmp(string s, string t){
    string ns = s+'#'+t;
    getnxt(ns);
    int szs = s.size(), sz = ns.size();
    vector<int> ret;
    for (int i=(szs<<1); i<sz; i++){
        if (nxt[i]==szs-1){
//            cout << i-(szs<<1)<<" ";
            ret.push_back(i-(szs<<1));
        }
    }
}

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    for (int i=1; i<=n; i++){
        cin>>s1[i]>>s2[i];
    }
    for (int i=1; i<=q; i++){
        string t1, t2;
        cin>>t1 >>t2;
//        cout<<t1<<" "<<t2<<endl;
        int ans=0;
        for (int ii=1; ii<=n; ii++){
//        cout<<s1[ii]<<" "<<s2[ii]<<endl;
            vector<int> v1=kmp(s1[ii], t1);
            vector<int> v2=kmp(s2[ii], t2);
//        cout<<s1[ii]<<"2 "<<s2[ii]<<endl;
            for (int i=0,j=0; i<v1.size(); i++){
                while (j<v2.size()&&v2[j]<v1[i]) j++;
                if (j==v2.size()) break;
                if (v2[j]!=v1[i]) continue;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
