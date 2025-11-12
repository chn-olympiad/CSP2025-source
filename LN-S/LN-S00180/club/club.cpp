#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAX1 = 1e5+10,MAX2 = 2e4+10;
ll t,n,a[MAX1][3],delta[3][MAX1],fav[3]={0,0,0},res=0,favo;
inline ll wmax(ll a,ll b,ll c){
    if (a > b){
        if (a > c) return 0;
        else return 2;
    }
    else{
        if (b > c) return 1;
        else return 2;
    }
}
inline ll wmin(ll a,ll b,ll c){
    if (a < b){
        if (a < c) return 0;
        else return 2;
    }
    else{
        if (b < c) return 1;
        else return 2;
    }
}
inline ll max1(ll a,ll b,ll c){
    return max(max(a,b),max(b,c));
}
inline ll max2(ll a,ll b,ll c){
    return a+b+c-max(max(a,b),max(b,c))-min(min(a,b),min(b,c));
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while (t--){
        fav[0]=0,fav[1]=0,fav[2]=0,res=0;
        cin >> n;
        for (ll i=0;i<n;i++){
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            fav[wmax(a[i][0],a[i][1],a[i][2])]++;
            res += max1(a[i][0],a[i][1],a[i][2]);
            delta[wmax(a[i][0],a[i][1],a[i][2])][i] = max1(a[i][0],a[i][1],a[i][2]) - max2(a[i][0],a[i][1],a[i][2]);
            delta[wmin(a[i][0],a[i][1],a[i][2])][i] = MAX2;
            delta[3-wmax(a[i][0],a[i][1],a[i][2])-wmin(a[i][0],a[i][1],a[i][2])][i] = MAX2;
        }
        favo = wmax(fav[0],fav[1],fav[2]);
        if (fav[favo] <= n/2){
            cout << res << '\n';
            continue;
        }
        sort(delta[favo],delta[favo]+n);
        for (ll i=0;i<fav[favo]-n/2;i++)
            res -= delta[favo][i];
        cout << res << '\n';
    }
    return 0;
}
