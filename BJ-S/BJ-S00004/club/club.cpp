#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream cin("club.in");
ofstream cout("club.out");

struct PPP {
    int a, b, c;
};

const int N = 1e5+5;
PPP a[N];
int n, c = 0;
long long s = 0;

bool mybigger(int x, int y, int z) {
    return x >= y && x >= z;
}

bool mycmpa(PPP x, PPP y) {
    return x.a > y.a;
}

void dprinta() {
    cout << c << endl;
    for(int i=0; i<n; i++) {
        cout << a[i].a << " " << a[i].b << " " << a[i].c << endl;
    }
    cout << endl;
}

void lu_a() {
    //cout << "a" << endl;
    int tc = c;
    sort(a, a+n, mycmpa);
    //dprinta();
    for(int i=0; i<n-tc && i<n/2; i++) {
        if(mybigger(a[i].a, a[i].b, a[i].c)) {
            s += a[i].a;
            c++;
            a[i].a = a[i].b = a[i].c = 0;
        } else {
            break;
        }
    }
    if(a[n/2].a != 0 && mybigger(a[n/2].a, a[n/2].b, a[n/2].c)) {
        for(int i=n/2; i<n-tc; i++) {
            if(mybigger(a[i].a, a[i].b, a[i].c)) {
                a[i].a = 0;
            } else {
                break;
            }
        }
    }
}

bool mycmpb(PPP x, PPP y) {
    return x.b > y.b;
}

void lu_b() {
    //cout << "b" << endl;
    int tc = c;
    //sort(a, a+n, mycmpb);
    dprinta();
    for(int i=0; i<n-tc && i<n/2; i++) {
        if(mybigger(a[i].b, a[i].a, a[i].c)) {
            s += a[i].b;
            c++;
            a[i].a = a[i].b = a[i].c = 0;
        } else {
            break;
        }
    }
    if(a[n/2].b != 0 && mybigger(a[n/2].b, a[n/2].a, a[n/2].c)) {
        for(int i=n/2; i<n-tc; i++) {
            if(mybigger(a[i].b, a[i].a, a[i].c)) {
                a[i].b = 0;
            } else {
                break;
            }
        }
    }
}

bool mycmpc(PPP x, PPP y) {
    return x.c > y.c;
}

void lu_c() {
    //cout << "c" << endl;
    int tc = c;
    //sort(a, a+n, mycmpc);
    dprinta();
    for(int i=0; i<n-tc && i<n/2; i++) {
        if(mybigger(a[i].c, a[i].b, a[i].a)) {
            s += a[i].c;
            c++;
            a[i].a = a[i].b = a[i].c = 0;
        } else {
            break;
        }
    }
    if(a[n/2].c != 0 && mybigger(a[n/2].c, a[n/2].b, a[n/2].a)) {
        for(int i=n/2; i<n-tc; i++) {
            if(mybigger(a[i].c, a[i].b, a[i].a)) {
                a[i].c = 0;
            } else {
                break;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        s = 0;
        c = 0;
        cin >> n;
        int wa, wb, wc;
        wa=wb=wc=0;
        for(int i=0;i<n;i++) {
            cin >> a[i].a >> a[i].b >> a[i].c;
            if(mybigger(a[i].a, a[i].b, a[i].c)) {
                wa++;
            } else if(mybigger(a[i].b, a[i].a, a[i].c)) {
                wb++;
            } else {
                wc++;
            }
        }
        if(mybigger(wa, wb, wc)) {
            lu_a();
            if(wb >= wc) {
                lu_b();
                lu_c();
            } else {
                lu_c();
                lu_b();
            }
        } else if(mybigger(wb, wa, wc)) {
            lu_b();
            if(wa >= wc) {
                lu_a();
                lu_c();
            } else {
                lu_c();
                lu_a();
            }
        } else {
            lu_c();
            if(wa >= wb) {
                lu_a();
                lu_b();
            } else {
                lu_b();
                lu_a();
            }
        }
        cout << s << endl;
    }
    return 0;
}

