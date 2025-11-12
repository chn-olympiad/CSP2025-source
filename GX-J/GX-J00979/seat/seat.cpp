#include <iostream>

using namespace std;

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int n,m; //n is total rows, m is total columns
    cin >> n >> m;

    int r_score;

    int r_i = 0;

    cin >> r_score;

    for(int _ = 1; _ < n*m; _++){
        int sb_score;
        cin >> sb_score;
        if(sb_score > r_score){
            r_i++;
        }
    }

    // cout << "i of R: " << r_i;

    

    // get column and row

    int c = r_i / n, r = r_i % n;

    // if c is ji shu, reverse r
    
    if(c&1){
        r = n - 1 - r;
    }

    cout << c+1 << ' ' << r+1;

    return 0;
}