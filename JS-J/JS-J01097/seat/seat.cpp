#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n*m];
    for(long long i=0;i<n*m;i++) cin>>a[i];
    long long num=a[0];
    sort(a,a+n*m,greater<long long>());
    long long x=1,y=1;
    long long add=1;
    for(long long i=0;i<n*m;i++) {
        if(a[i]==num) {
            cout<<x<<" "<<y;
            return 0;
        }
        if(y==1&&add==-1) {
            add=1;
            x++;
        }
        else if(y==n&&add==1) {
            add=-1;
            x++;
        }
        else y+=add;
    }
    return 0;
}