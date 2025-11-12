#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int n,m,c;
int s[20][20];
struct stu {
    int num,no;
};
stu a[N];
bool cmp(stu a,stu b) {
    return a.num>b.num;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++) {
        cin>>a[i].num;
        a[i].no=i;
    }
    int sum=1;
    for (int i=1;i<=m;i++) {
        if (i%2==1) {
            for (int j=1;j<=n;j++) {
                s[j][i]=sum;
                sum++;
            }
        }
        else {
            for (int j=n;j>=1;j--) {
                s[j][i]=sum;
                sum++;
            }
        }
    }
    sort(a+1,a+1+n*m,cmp);
    for (int i=1;i<=n*m;i++) {
        if (a[i].no==1) {
            c=i;
            break;
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (s[i][j]==c) {
                cout<<j<<' '<<i;
                return 0;
            }
        }
    }
}
