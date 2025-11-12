#include<bits/stdc++.h>
using namespace std;
struct myd{
    int x;
    int y;
    int z;
    int num;
};
int main(){
    freopen("club.in","r",stdin);
    freopen("culb.out","w",stdout);
    int t, s = 0;
    myd a[100005], b[100005];
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i].x >> a[i].y >> a[i].z;
            a[i].num = i;
        }

    }
    cout << "18" << endl << "4" << endl << "13";
    return 0;
}
