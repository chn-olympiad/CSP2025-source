#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,r,a[110],c;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i<=n*m;i++){
        int x;
        cin >> x;
        if(i == 1)r = x;
        a[i] = x;
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i = 1;i<=n*m;i++)if(a[i] == r)c = i;
    int b = c%(2*n);
    cout << (c-1)/n+1<< ' ';
    if(b == 0)b = 2*n;
    if(b>n)cout << 2*n+1-b;
    else cout << b;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
