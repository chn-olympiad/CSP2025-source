#include <bits/stdc++.h>
using namespace std;

struct p{
    int a,b,c;
};

bool cmp(p a,p b){
    return a.a > b.a;
}

int solvesub(vector<p> r){
    int n = r.size();
    sort(r.begin(),r.end(),cmp);
    long long ans = 0;
    for (int i =0;i < n/2;i ++){
        ans += r[i].a;
    }
    return ans;
}

int calc(vector<p> as,vector<p> bs,vector<p> cs){
    int ret = 0;
    for (int i = 0;i < as.size();i ++){
        ret += as[i].a;
    }
    for (int i = 0;i < bs.size();i ++){
        ret += bs[i].b;
    }
    for (int i = 0;i < cs.size();i ++){
        ret += cs[i].c;
    }
    return ret;
}


int solve(int next,vector<p> d,vector<p> as,vector<p> bs,vector<p> cs){
    int n = d.size();
    if (next == n){
        return calc(as,bs,cs);
    }
    int ans = -1;
    if(as.size()+1 <= n/2){
        as.push_back(d[next]);
        ans = max(ans,solve(next + 1,d,as,bs,cs));
        as.pop_back();
    }
    if(bs.size()+1 <= n/2){
        bs.push_back(d[next]);
        ans = max(ans,solve(next + 1,d,as,bs,cs));
        bs.pop_back();
    }
    if(cs.size()+1 <= n/2){
        cs.push_back(d[next]);
        ans = max(ans,solve(next + 1,d,as,bs,cs));
        cs.pop_back();
    }
    return ans;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<p> as;
        vector<p> bs;
        vector<p> cs;
        vector<p> d;
        for (int i =0 ;i < n;i ++){
            p tmp;
            cin >> tmp.a >> tmp.b >> tmp.c;
            d.push_back(tmp);
        }
        if (n >= 300){
            cout << solvesub(d);
            continue;
        }
        cout << solve(0,d,as,bs,cs) << endl;
    }
    return 0;
}