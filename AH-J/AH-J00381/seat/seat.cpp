#include<bits/stdc++.h>
using namespace std;

int n,m,s[1001][1001],t1,t2,a[1001],k;

bool cmp(int a,int b) {
    return a>b;
}

int main () {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++) {
        cin>>a[i];
    }
    t1=a[1];
    sort(a+1,a+n*m+1,cmp);
    k=1;
    int x=1,y=1;
    while (k<=n*m) {
        while (x<=n&&k<=n*m) {
            s[x][y]=a[k];
            x++;
            k++;
        }
        y+=1;
        x-=1;
        while (x>=1&&k<=n*m) {
            s[x][y]=a[k];
            x--;
            k++;

        }
        x+=1;
        y+=1;
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (s[i][j]==t1) {
                cout<<j<<' '<<i;
                return 0;
            }
        }
    }
    return 0;
}
