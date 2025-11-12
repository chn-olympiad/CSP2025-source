#include <bits/c++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,a,pf,r;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>a;
        int max=a/2;
        max++;
        int rs[3]={0,0,0}
        for(int j=0;j<a;j++)
        {
            int big=0;
            for(int q=0;q<3;q++)
            {
                cin>>r;
                if(r>big && rs[q]<max)
                {
                    big=r;
                }
            }
            pf+=big;
        }
    }
    cout<<pf<<endl;
    return 0;
}
