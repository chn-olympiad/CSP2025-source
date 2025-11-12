#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,q;
string a[200005][2],qa,qb;

void input(){
    cin >> n >> q;
    for(int i = 1;i <= n;++i){
        cin >> a[i][0] >> a[i][1];
    }
}

signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    input();
    while(q--){
        cin >> qa >> qb;
        if(qa.size()!=qb.size()){cout << "0\n";continue;}
        int ql,qr,ans = 0;
        for(ql = 0;qa[ql]==qb[ql];++ql);
        for(qr = qa.size()-1;qa[qr]==qb[qr];--qr);
        string diffa = qa.substr(ql,qr-ql+1),diffb = qb.substr(ql,qr-ql+1);
        //cout << diffa << ' ' << diffb << '\n';
        for(int i = 1;i <= n;++i){
            //cout << i << endl;
            int qal,qar;
            if(a[i][0]==a[i][1])continue;
            for(qal = 0;a[i][0][qal]==a[i][1][qal];++qal);
            for(qar = a[i][0].size()-1;a[i][0][qar]==a[i][1][qar];--qar);
            string diffaa = a[i][0].substr(qal,qar-qal+1),diffab = a[i][1].substr(qal,qar-qal+1);
            //cout << diffaa << ' ' << diffab << '\n';
            if(diffa==diffaa&&diffb==diffab&&qa.find(diffa)!=-1)ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
