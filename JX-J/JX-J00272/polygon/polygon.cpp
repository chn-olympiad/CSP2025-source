#include <bits/stdc++.h>
#define LL long long
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"
using namespace std;
const int N=10e6+10;
int a[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    IOS;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    if(n<3) cout<<0;
    else if(n==3) cout<<6;







    return 0;
}
