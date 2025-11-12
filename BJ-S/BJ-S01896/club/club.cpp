#include<bits/stdc++.h>
#define int long long
#define pp std::cout << "test\n"
using namespace std;

int a[100005][3], n, t;
signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    for(int _=0;_<t;_++){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a[i][0] >> a[i][1] >> a[i][2];
        }
        int cnt1=0, cnt2=0, cnt3=0, s=0;
        vector<int> vv1, vv2, vv3;
        for(int i=0;i<n;i++){
            if(max(a[i][0], max(a[i][1], a[i][2])) == a[i][0]){
                vv1.push_back(i);
                cnt1++;
                s += a[i][0];
            }else if(max(a[i][0], max(a[i][1], a[i][2])) == a[i][1]){
                vv2.push_back(i);
                cnt2++;
                s += a[i][1];
            }else{
                vv3.push_back(i);
                cnt3++;
                s += a[i][2];
            }
        }
        if(cnt1 > n / 2){
            sort(vv1.begin(), vv1.end(), [](int i, int j){return min(a[i][0] - a[i][1], a[i][0] - a[i][2]) < min(a[j][0] - a[j][1], a[j][0] - a[j][2]);});
            int ptr=0;
            while(cnt1 > n / 2){
                cnt1--;
                s -= a[vv1[ptr]][0];
                s += max(a[vv1[ptr]][1], a[vv1[ptr]][2]);
                ptr++;
            }
            cout << s << endl;
        }else if(cnt2 > n / 2){
            sort(vv2.begin(), vv2.end(), [](int i, int j){return min(a[i][1] - a[i][0], a[i][1] - a[i][2]) < min(a[j][1] - a[j][0], a[j][1] - a[j][2]);});
            int ptr=0;
            while(cnt2 > n / 2){
                cnt2--;
                s -= a[vv2[ptr]][1];
                s += max(a[vv2[ptr]][0], a[vv2[ptr]][2]);
                ptr++;
            }
            cout << s << endl;
        }else if(cnt3 > n / 2){
            sort(vv3.begin(), vv3.end(), [](int i, int j){return min(a[i][2]- a[i][1], a[i][2] - a[i][0]) < min(a[j][2] - a[j][1], a[j][2] - a[j][0]);});
            int ptr=0;
            while(cnt3 > n / 2){
                cnt3--;
                s -= a[vv3[ptr]][2];
                s += max(a[vv3[ptr]][1], a[vv3[ptr]][0]);
                ptr++;
            }
            cout << s << endl;
        }else{
            cout << s << endl;
        }
    }
}
