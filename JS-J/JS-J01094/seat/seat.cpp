#include<bits/stdc++.h>
using namespace std;

int my_x[2] = {1, -1};
long long n;
long long m;

bool my_bool(long long x, long long y) {
    if(x > n || x <= 0) return false;
    else return true;
}

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    long long tmp, k = 0;
    long long my_self;
    long long x = 1, y = 1;
    int my_toward = 0;
    cin>>n>>m;
    cin>>my_self;
    for(int i = 1; i < n * m; i++) {
        cin>>tmp;
        if(tmp > my_self) {
            k++;
        }
    }
    while(k--) {
        if(my_bool(x + my_x[my_toward], y)) {
                x += my_x[my_toward];
                //cout<<"("<<y<<","<<x<<")"<<endl;
        }else {
            y++;
            if(my_toward == 0) my_toward = 1;
            else my_toward = 0;
            //cout<<"("<<y<<","<<x<<")"<<my_toward<<endl;
        }
    }
    cout<<y<<" "<<x;
    return 0;
}
