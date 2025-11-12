#include <iostream>
#include <bits/stdc++.h>
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
using namespace std;
int a[109];

int main()
{
    long long n,m;
    cin >> n >> m;
    int x,l=1;
    cin >> x;
    for (int i=1;i<n*m;i++){
        cin >> a[i];
        if(a[i]>x){
            l++;
        }
    }
    int L;
    if(l%n!=0){
        cout << l/n+1 << ' ';
        L=l/n+1;
    }else{
        cout << l/n << ' ';
        L=l/n;
    }
    if(L%2==0){
        cout << n-l%n+1;
    }else{
        if(l%n==0){
            cout << n;
        }else{
            cout << l%n;
        }
    }
    return 0;
}
