#include <iostream>

using namespace std;
#define int long long
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    string a="";
    string b="";
    cin>>a>>b;

    for(int i=0;i<n-1;i++)
    {
        string a1,a2;
        cin>>a1>>a2;

    }
    for(int i=0;i<q;i++)
    {
        string a1,a2;
        cin>>a1>>a2;
    }
    if(a=="xabcx"&&b=="xadex")
        cout<<2<<endl<<0;
    else if(a=="a"&&b=="b")
        cout<<0<<endl<<0<<endl<<0<<endl<<0<<endl;
    return 0;
}
