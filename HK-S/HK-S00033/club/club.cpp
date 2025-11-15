#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct C{
    bool rn = 1;
    int st = 0; //0 = first

    vector<pair<ll, int>> minus;

};


int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<vector<ll>> a(n, vector<ll>(3));


        vector<C> all;
        for(int x=0; x<n; x++){
            for(int y=0; y<3; y++) cin >> a[x][y];
        }

        for(int x=0; x<n; x++){
            C in;
            vector<pair<ll, int>> ct;
            for(int y=0; y<3; y++){
                ct.push_back({a[x][y], y});
            }

            sort(ct.begin(), ct.end());
            reverse(ct.begin(), ct.end());

            for(int y=0; y<3; y++){
                in.minus.push_back(ct[y]);
            }
            all.push_back(in);
        }//sort

        int ct0 = 0, ct1 = 0, ct2 = 0, target = -1;
        
        ll out = 0;
        for(int x=0; x<n; x++){
            C r = all[x];
            int place = r.minus[0].second;
            if(place == 0) ct0++;
            else if(place == 1) ct1++;
            else ct2++;
            out += r.minus[0].first;
        }

        //cout << "@" << out << endl;

        if(ct0 > n/2) target = 0;
        else if(ct1 > n/2) target = 1;
        else if(ct2 > n/2) target = 2;

        while((ct0 > n/2) || (ct1 > n/2) || (ct2 > n/2)){
            ll minv = LONG_LONG_MAX;
            int minp;
            for(int x=0; x<n; x++){
                C r = all[x];
                if(r.rn && r.minus[r.st].second == target){
                    if((r.minus[r.st].first - r.minus[r.st+1].first) < minv){
                        minv = (r.minus[r.st].first - r.minus[r.st+1].first);
                        minp = x;
                    }
                }
            }

            if(target == 0) ct0--;
            else if(target == 1) ct1--;
            else ct2--;

            out -= minv;
            all[minp].rn = 0;
        }

        cout << out << endl;
    }
}