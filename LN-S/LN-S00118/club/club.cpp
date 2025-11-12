#include<bits/stdc++.h>
using namespace std;
int n,a[100001][4],T;
bool cmp(int x,int y){
    return a[x][0] < a[y][0];
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> T;
    for(int p = 1;p <= T;p++){
        int sum = 0;
        vector<int> c1,c2,c3;
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            int l = max(a[i][1],max(a[i][2],a[i][3]));
            if(a[i][1] == l) c1.push_back(i),a[i][0] = l - max(a[i][2],a[i][3]);
            else if(a[i][2] == l) c2.push_back(i),a[i][0] = l - max(a[i][1],a[i][3]);
            else if(a[i][3] == l) c3.push_back(i),a[i][0] = l - max(a[i][1],a[i][2]);
            sum += l;
        }
        if(c1.size() > n / 2) {
            sort(c1.begin(),c1.end(),cmp);
            for(int j = 0;j < c1.size() - n / 2;j++) sum -= a[c1[j]][0];
        }
        if(c2.size() > n / 2) {
            sort(c2.begin(),c2.end(),cmp);
            for(int j = 0;j < c2.size() - n / 2;j++) sum -= a[c2[j]][0];
        }
        if(c3.size() > n / 2) {
            sort(c3.begin(),c3.end(),cmp);
            for(int j = 0;j < c3.size() - n / 2;j++) sum -= a[c3[j]][0];
        }
        cout << sum << endl;
    }
    return 0;
}
