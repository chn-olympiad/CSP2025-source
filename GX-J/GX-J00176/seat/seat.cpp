#include<bits/stdc++.h>
using namespace std;

const int N=105;
int n,m,a[N],x[N],idx=1;
bool cmp(int x,int y) {return x>y;}
int main() {
    //freopen("seat4.in","r",stdin);
    //freopen("seat4.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++) cin>>a[i];
    int r=a[1];
    sort(a+1,a+n*m+1,cmp);
    for (int i=1;(100-idx)>0;i++) {
        for (int j=1;j<=n;j++){
            x[idx++]=j;
        }
        for (int k=n;k>=1;k--) {
            x[idx++]=k;
        }
    }
    for (int i=1;i<=n*m;i++) {
        if (a[i]==r) {
            double t=i*1.0;
            int y=ceil(t/n);
            cout<<y<<" "<<x[i];
            break;
        }
    }
    return 0;
}
