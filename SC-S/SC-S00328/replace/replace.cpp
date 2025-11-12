#include <bits/stdc++.h>
#define eps (int)(5e6+1)
using namespace std;

int n,q;
const int N = 1e7 + 3;
unordered_map<string,vector<string>> mp;
long long ans = 0;
bool flag = true;
vector<pair<int,int>> arr[N];

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    if(n > 1e3){
        for(int i = 1;i <= n;i++){
            string a,b;
            cin >> a >> b;
            int posa,posb;
            int lf,rf;
            int sza = a.size();
            for(int j = 0;j < sza;j++){
                if(a[j] == 'b'){
                    posa = j;
                    lf = j;
                    rf = sza - j - 1;
                    break;
                }
            }
            for(int j = 0;j < sza;j++){
                if(b[j] == 'b'){
                    posb = j;
                    break;
                }
            }
            arr[posa - posb + eps].push_back({lf,rf});
        }
        while(q--){
            ans = 0;
            string a,b;
            cin >> a >> b;
            int posa,posb;
            int lf,rf;
            int sza = a.size();
            for(int j = 0;j < sza;j++){
                if(a[j] == 'b'){
                    posa = j;
                    lf = j;
                    rf = sza - j - 1;
                    break;
                }
            }
            for(int j = 0;j < sza;j++){
                if(b[j] == 'b'){
                    posb = j;
                    break;
                }
            }
            for(int i = 0;i < (int)arr[posa - posb + eps].size();i++){
                if(lf >= arr[posa - posb + eps][i].first && rf >= arr[posa - posb + eps][i].second){
                    ans++;
                }
            }
            cout << ans << "\n";
        }
        return 0;
    }
    for(int i = 1;i <= n;i++){
        string a,b;
        cin >> a >> b;
        mp[a].push_back(b);
    }
    while(q--){
        string a,b;
        cin >> a >> b;
        int sza = a.size();
        int minpos = INT_MAX,maxpos = -1;
        for(int i = 0;i < sza;i++){
            if(a[i] != b[i]){
                minpos = min(minpos,i);
                maxpos = max(maxpos,i);
            }
        }
        ans = 0;
        for(int i = 0;i <= minpos;i++){
            for(int j = maxpos;j < sza;j++){
                string tmp = a.substr(i,j - i + 1),tmp2 = b.substr(i,j - i + 1);
                if(mp.count(tmp)){
                    for(int k = 0;k < (int)mp[tmp].size();k++){
                        if(mp[tmp][k] == tmp2){
                            ans++;
                        }
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}