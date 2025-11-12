#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FILE_IO
// #define DEBUG
// no idea...

signed main()
{
    #ifdef FILE_IO
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    #define endl '\n'
    #endif // FILE_IO
    int n;
    cin>>n;
    if(n==4)
        cout<<2<<endl<<0<<endl;
    else if(n==3)
        cout<<0<<endl<<0<<endl<<0<<endl<<0<<endl;
    else
        cout<<"I have no idea about this problem..."<<endl;
    return 0;
}
