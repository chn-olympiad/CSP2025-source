#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    #ifndef NOFREOPEN
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    #endif // NOFREOPEN
    int n,m;
    cin>>n>>m;
    int a,num=1;
    cin>>a;
    for(int i=1;i<n*m;i++){
        int temp;
        cin>>temp;
        if(temp>a) num++;
    }
    int i=num%n;
    int j=(num+n-1)/n;
    if(!(j&1)) i=n-i+1;
    if(!i) i+=n;
    cout<<j<<' '<<i;
}
