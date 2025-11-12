#include <iostream>
using namespace std;
struct mem {
    int a1;
    int b1;
    int c1;
    int bm;
    int f() {
        if (bm==a1)return 0;
        if (bm==b1)return 1;
        return 2;
    }
};
struct ou {
    int sum;
    int minn;
    int so;
    int so1=-1;
    int x;
    int y;
    int n;
    void u(int i,int j,int n1) {
        sum++;
        if (so<so1) {
            minn=so;
            x=i;
            y=j;
            n=n1;
        }
        so1=so;
    }
};
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int nn;
    cin >> nn;
    int n[nn];
    ou bu[nn][3];
    mem a[nn][100000];
    for (int i=0;i<nn;i++) {
        cin >> n[i];
        for (int j=0;j<n[i];j++) {
            cin >> a[i][j].a1 >> a[i][j].b1 >> a[i][j].c1;
            a[i][j].bm=max(a[i][j].a1,max(a[i][j].b1,a[i][j].c1));
            bu[i][a[i][j].f()].so+=a[i][j].bm;
            bu[i][j].u(i,j,n[i]);
        }
    }
    int coutt[nn];
    for (int i=0;i<nn;i++) {
        coutt[i]=0;
        for (int j=0;j<n[i];j++) {
            coutt[i]+=(a[i][j].bm);
        }
        cout << coutt[i] << endl;
    }
    return 0;
}
