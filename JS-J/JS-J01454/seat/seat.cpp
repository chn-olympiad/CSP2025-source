#include <bits/stdc++.h>
using namespace std;
int n,m,r,rp,rt;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    cin >> r;
    rp=1;
    for(int i = 1;i <n*m;i++)
        if(cin >> rt,rt>r) rp++;
    int a,b;
    a=rp/n;
    if(rp%n) a++;
    if(a%2){
        b=rp-(a-1)*n;
    }else b = n-rp+(a-1)*n+1;
    cout << a <<" "<< b;
    return 0;
}
