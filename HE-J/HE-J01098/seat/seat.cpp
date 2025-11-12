#include <iostream>
#include <algorithm>

using namespace std;

int a[105];

bool cmp(const int &a, const int &b){ //
    return a > b;
}

int main(){

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    cin >> n >> m;
    for(int i = 1; i<= n*m; i++){
        cin >> a[i];
    }

    int a1 = a[1];
    int c,r,p;

    sort(a+1,a+(n*m)+1,cmp);

    for(int i = 1; i<= n*m; i++){
        if(a[i] == a1) {
            p = i;
        }
    }


    if(p%n == 0) c=p/n;
    else c=p/n +1;

    r = p - ( (c - 1) *n);

    if(c % 2 == 0){
        r = n - r +1;
    }

    cout << c << " " << r;

    return 0;
}
