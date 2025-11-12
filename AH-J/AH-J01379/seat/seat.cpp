#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;

int n,m,a[105];
int R;
int c[105],r[105];
bool cmp(int x,int y) {
    return x>y;
}
int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) {
        cin>>a[i];
    }
    R=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++) {
        int tmp1=(i-1)/n,tmp2=(i-1)%n;
        c[i]=tmp1+1;
        if(tmp1%2==0) {
            r[i]=tmp2+1;
        }
        else {
            r[i]=n-tmp2;
        }
        if(a[i]==R) {
            cout<<c[i]<<" "<<r[i];
            return 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
