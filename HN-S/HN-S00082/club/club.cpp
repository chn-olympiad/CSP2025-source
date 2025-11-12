#include<bits//stdc++.h>
using namespace std;
using gg = long long;

const gg N = 1e5+5;
gg t,n,x,y,z,r,cnt,ans;
bool flag;

struct person{
    gg rk = 0;
    gg d[3] = {};
    gg maxx[3] = {};
    person(){}
    person(gg r,gg a,gg b,gg c){
        rk = r,d[0] = a,d[1] = b,d[2] = c;
        if(a >= b and b >= c){
            maxx[0] = 0,maxx[1] = 1,maxx[2] = 2;
        }else if(a >= c and c >= b){
            maxx[0] = 0,maxx[1] = 2,maxx[2] = 1;
        }else if(b >= c and c >= a){
            maxx[0] = 1,maxx[1] = 2,maxx[2] = 0;
        }else if(b >= a and a >= c){
            maxx[0] = 1,maxx[1] = 0,maxx[2] = 2;
        }else if(c >= a and a >= b){
            maxx[0] = 2,maxx[1] = 0,maxx[2] = 1;
        }else if(c >= b and b >= a){
            maxx[0] = 2,maxx[1] = 1,maxx[2] = 0;
        }
    }
}p[N];

bool cmp(person a,person b){
    if(a.d[a.maxx[0]] == b.d[b.maxx[1]]){
        if(a.d[a.maxx[1]] == b.d[b.maxx[1]]){
            return a.d[a.maxx[2]] > b.d[b.maxx[2]];
        }
        return a.d[a.maxx[1]] < b.d[b.maxx[1]];
    }
    return a.d[a.maxx[0]] > b.d[b.maxx[0]];
}

void dfs(gg m,gg x,gg y,gg z,gg v){
    if(m == n){
        ans = max(ans,v);
        return;
    }
    if(x < n/2) dfs(m+1,x + 1,y,z,v+p[m].d[0]);
    if(y < n/2) dfs(m+1,x,y + 1,z,v+p[m].d[1]);
    if(z < n/2) dfs(m+1,x,y,z + 1,v+p[m].d[2]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin >> t;
    while(t--){
        flag = 1;
        ans = cnt = 0;
        cin >> n;
        for(gg i = 0;i<n;++i){
            cin >> x >> y >> z;
            if(y != 0) flag = 0;
            p[i] = (person){i,x,y,z};
        }
        sort(p,p+n,cmp);
        for(gg i =0;i<n/2;++i){
            cnt += p[i].d[0];
        }
        if(flag) {
            cout << cnt << '\n';
            continue;
        }else{
            dfs(0,0,0,0,0);
            cout << ans << '\n';
        }
    }

    return 0;
}
