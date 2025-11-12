#include <bit/stdC++.h>
using namespace std;
int main()
{
    freopen("xor.in","r","stdin");
    freopen("xor.out","w","stdout");
    int a;
    int b;
    cin>>a;
    cin>>b;
    int k;
    cin>>k;
    if(a^k>b^k)
    {
        cout<<a^k;
    }
    if(a^k<b^k)
    {
        cout<<b^k;
    }
    if(a^k==b^k)
    {
        cout<<a^k;
    }
    return 0;
}
