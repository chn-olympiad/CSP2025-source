#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
#define NMAX 150000
using namespace std;
struct peo{
    ll sc;
    int belong;
};
bool bmp(peo a,peo b){
    return a.sc > b.sc;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w+",stdout);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll x,y,z;
        vector<peo> all;
        for(int i = 0;i < n;i++){
            cin >> x >> y >> z;
            all.push_back((peo){x ,1});
            all.push_back((peo){y ,2});
            all.push_back((peo){z ,3});
        }
        sort(all.begin(),all.end(), bmp);
        ll k[4];
        ll ans = 0;
        k[1] = k[2] = k[3] = n / 2;
        for(int i = 0;i < n;i++){
            if(k[all[i].belong] != 0){
                k[all[i].belong]--;
                ans += all[i].sc;
            }
            if(k[1] == 0 && k[2] == 0 && k[3] == 0)break;
        }
        cout << ans << endl;
    }
    return 0;
}
