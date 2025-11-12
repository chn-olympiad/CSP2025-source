#include <bits/stdc++.h>
using namespace std;
int n,m,val,c,r; //n row, m col
int a[102];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for (int i=0;i<n*m;i++){
        cin >> a[i];
    }
    val=a[0];
    int pos=1;
    sort(a,a+n*m);
    while (a[n*m-pos]!=val)pos++;
    c=(pos-1)/n+1; //col
    r=c%2==1?pos%n+(pos%n?0:n):n-(pos-1)%n; //row
    cout << c << ' ' << r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
