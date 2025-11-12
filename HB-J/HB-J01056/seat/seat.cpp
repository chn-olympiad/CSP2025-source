#include <iostream>
#include <vector>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    cin >> n >> m;
    int seat_num = n * m;
    vector<int> a(seat_num,0);

    for(int i = 0;i < a.size();i++){
        cin >> a[i];
    }
    int r = a[0];
    int cnt = 0;
    for(int i = 1;i < seat_num;i++){
        if(a[i] > r)cnt++;
    }

    int x = 1,y = 1;
    bool flag = 1,next = 0;
    for(int i = 0;i < cnt;i++){
        if(next){
            y++;
            next = 0;
            continue;
        }
        if(flag){
            x++;
            if(x == n){
                flag = 0;
                next = 1;
            }
        }else{
            x--;
            if(x == 1){
                flag = 1;
                next = 1;
            }
        }
    }
    cout << y << " " << x;


	return 0;
}
