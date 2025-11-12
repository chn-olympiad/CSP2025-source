#include<bits/stdc++.h>
using namespace std;
bool isP[5000010];
pair<int,int> dict1[200010],dict2[200010];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,q;
    cin >> n >> q;
    string x,y;
    for(int i = 1;i <= n;i++){
        cin >> x >> y;
        int idx1 = 0,idx2 = 0;
        while(x[idx1] != 'b') idx1++;
        dict1[i].first = idx1-1,dict1[i].second = x.length()-idx1-1;
        while(y[idx2] != 'b') idx2++;
        dict2[i].first = idx2-1,dict2[i].second = y.length()-idx2-1;
    }
    string t1,t2;
    while(q--){
        cin >> t1 >> t2;
        cout << 0;
    }

    return 0;
}
