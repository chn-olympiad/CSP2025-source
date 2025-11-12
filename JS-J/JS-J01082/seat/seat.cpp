#include <bits/stdc++.h>
using namespace std;

int arr[105],square[15][15];
int numn,m;

bool cmp(int anum,int bnum){
    return anum > bnum;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);

    cin >> numn >> m;
    for(int ilon = 0;ilon < numn * m;ilon ++){
        cin >> arr[ilon];
    }
    int r = arr[0];
    int flag = 1;
    int t = 0,ilon = 1,jesi = 1;
    sort(arr,arr + numn * m,cmp);
    for(;jesi <= m;jesi ++){
        if(jesi % 2 == 1){
            flag = 1;
            ilon = 1;
        } else {
            flag = -1;
            ilon = numn;
        }
        for(;ilon > 0 && ilon <= numn;ilon += flag){
            square[ilon][jesi] = arr[t];
            t ++;
        }
    }
    //for(int i = 0;i < n * m;i ++){
    //    cout << a[i];
    //}
    for(ilon = 1;ilon <= numn;ilon ++) {
        for(jesi = 1;jesi <= m;jesi ++) {
            if(square[ilon][jesi] == r) {
                cout << jesi << ' ' << ilon;
                return 0;
            }
            //cout << s[i][j] << ' ';
        }
        //cout << endl;
    }
    //cout << i << ' ' << j << ' ' << t;
    return 0;
}
