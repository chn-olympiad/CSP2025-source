#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen ("number.in","r",stdin);
    freopen ("number.out","w",stdout);
    string u;
    cin>>u;
    int bj=sizeof(u);
    int uy[bj]={0};
    for(int i=0;i<bj;i++)
    {
        if(u[i]>='0' && u[i]<='9')
        {
            uy[i]=u[i];
        }
        else
        {
                bj--;
        }
    }
    sort (uy,uy+bj);
    for(int i=bj-1;i>=0;i--)
    {
        cout<<uy[i];
    }
    return 0;
}
