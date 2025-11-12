#include <bits/stdc++.h>
using namespace std;
const long long MAXNM = 11*11;
int n, m;
long long a[MAXNM];
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    int nm = n*m;
    for(int i = 1; i <= nm; i++){
        cin >> a[i];
    }
    int little_R = a[1], Ridx;
    sort(a+1, a+1+nm, greater<int>());
    for(int i = 1; i <= nm; i++){
        if(a[i] == little_R){
            Ridx = i;
        }
    }
    int r = 1, c = 1;
    for(int i = 1; i <= nm; i++){
        if(i == Ridx){
            cout << c << " " << r << endl;
            return 0;
        }
        if(c % 2 == 1 && r == n) c++;
        else if(c % 2 == 0 && r == 1) c++;
        else if(c % 2 == 1) r++;
        else r--;
    }
}
