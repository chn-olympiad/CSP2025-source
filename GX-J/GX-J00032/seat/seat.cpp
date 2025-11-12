#include<bits/stdc++.h>
using namespace std;
int x=1,y=1;
int main()
{
    feropen("seat.in","r",stdin);
    feropen("seat.out","w",stdout);
    int n,m,c;
    cin>>n>>m>>c;
    for(int i=2;i<=n*m;i++)
    {
        cin>>i;
        if(i>=c)
        {
            x++;

        }
        if(x>=n)
            {
                x-i;
                y++;
            }
    }
    cout<<y<<" "<<x<<endl;
    return 0;
}
