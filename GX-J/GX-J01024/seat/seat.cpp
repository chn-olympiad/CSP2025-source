#include <bits/stdc++.h>
using namespace std;
int nn,mm,zz,aa[106];
bool cmp(int x,int y)
{
    return x > y;
}
int main()
{
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    cin >> nn >> mm;
    cin >> zz;
    aa[1] = zz;
    for(int i=2;i <= nn*mm;i++)
        cin >> aa[i];
    sort(aa+1,aa+nn*mm+1,cmp);
    for(int i=1;i <= nn*mm;i++)
    {
        if(aa[i] == zz)
        {
            if(i%nn == 0)
            {
                cout << i/nn << ' ';
                if((i/nn)%2==0)
                    cout << 1;
                else
                    cout << nn;
            }
            else
            {
                cout << i/nn+1 << ' ';
                if((i/nn+1)%2==1)
                    cout << i%nn;
                else
                    cout << nn-(i%nn)+1;
            }
        }
    }
    return 0;
}
