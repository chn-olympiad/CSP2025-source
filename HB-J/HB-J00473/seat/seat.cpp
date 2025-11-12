#include<bits/stdc++.h>
using namespace std;
int a[105];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int h = n*m;
    for (int i=1;i<=h;i++) cin >> a[i];
    int k,v;
    v = a[1];
    sort(a+1,a+1+h);
    for (int i=1;i<=h;i++)
        if (a[i]==v){
            k = h-i+1;
            continue;
        }
    int l = (k+n-1)/n,y;
    if (k%n==0) y = n;
    else y = k%n;
    if (l%2!=0) cout << l << " " << y;
    else cout << l << " " << n-y+1;
    return 0;
}