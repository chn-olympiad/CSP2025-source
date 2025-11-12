#include <bits/stdc++.h>
using namespace std;
int main ()
{
    freopen ("seat.in","r",stdin);
    freopen ("seat.out","w",stdout);
    int m,n;
    cin>>m>>n;

    int cj[m*n]={0};
    for(int i=0;i<m*n;i++)
    {
        cin>>cj[i];
    }
    int yu=cj[0];
    int y=m*n;
    sort(cj,cj+y);
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<m;j++)
       {
            if(cj[m*i-j]==yu)
            {
                cout<<n<<" "<<m;
                break;
            }
       }
       i++;
       for(int j=m-1;j>=0;j--)
       {
            if(cj[m*i-m+j]==yu)
            {
                cout<<n<<" "<<m;
                break;
            }
       }
    }
    return 0;
}
