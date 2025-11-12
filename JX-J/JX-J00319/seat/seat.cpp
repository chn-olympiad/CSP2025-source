#include<bits/stdc++.h>
using namespace std;

const int N = 1E6 + 10;
int n, m;
int score[N];
bool cmp(int a, int b){
    return a > b;
}
int x = 1, y = 1;
int now = 0;
int own;
int pos = 1;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++){
        cin >> score[i];
    }
    own = score[1];
    sort(score + 1, score + 1 + n * m, cmp);
    while(y <= m){
        if(now % 2 == 0){
            while(x <= n){
                //cout << "now:[" << x << ',' << y << ']'<< " and pos = " << pos << "\n";
                if(score[pos] == own){
                    cout << y << ' ' << x;
                    return 0;
                }
                x++;
                pos++;
            }
            now = 1;
            x = n;
        } else if(now % 2 == 1){
            while(x >= 1){
                //cout << "now:[" << x << ',' << y << ']'<< " and pos = "<< pos << "\n";
                if(score[pos] == own){
                    cout << y << ' ' << x;
                    return 0;
                }
                x--;
                pos++;
            }
            now = 0;
            x = 1;
        }
        y++;
    }
    return 0;
}
