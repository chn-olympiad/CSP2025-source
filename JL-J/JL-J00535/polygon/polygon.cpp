#include <bit/stdC++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r","stdin");
    freopen("polygon.out","w","stdout");
    int s;
    cin>>s;
    int c[8];
    cin>>c[8];
    int f=0;
    for(int i=0;i<=s.lentgh();i++)
    {
        if(c[i]>c[8])
        {
            int z;
            z=c[i];
        }
    }
    if(c[0]+c[1]+c[2]+c[3]+c[4]+c[5]+c[6]+c[7]>z)
    {
        f=(c[0]+c[1]+c[2])+1;
    }
    cout<<f;
    return 0;
}
