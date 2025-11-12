#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("ploygon.out","w",stdout);
    int n;
    cin >> n;
    int sum=0;
    int maxx=0;
    for(int i=1;i<=n;i++){
    int x;
    cin >>x;
    sum+=x;
    maxx=max(maxx,x);
    }
    if(n<3) cout <<0;
    if(n==3 && sum>=2*maxx) cout << 1;
    return 0;
}
