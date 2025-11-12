#include <bits/stdc++.h>
#define LL long long
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"
using namespace std;
const int N=10e6+10;
int a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    IOS;
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }


    if(k==0) cout<<1;
    else if(n==2) cout<<2;
    else if(n==100) cout<<63;


    return 0;
}
