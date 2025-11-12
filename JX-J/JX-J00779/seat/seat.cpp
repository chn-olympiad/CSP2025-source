#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b,c[110];
    cin>>a>>b;
    for(int i=1;i<=a*b;i++)
    {
        cin>>c[i];
    }
    int d=c[1];
    sort(c+1,c+a*b+1);
    for(int i=1;i<=a*b;i++)
    {
        if(c[i]==d)
        {
            i=a*b-i+1;
            int z=i/a;
            int y=i%a;
            if(y!=0)
            {
                z+=1;
            }
            else
            {
                y+=a;
            }
            if(z%2==1)
            {
                cout<<z<<" "<<y;
            }
            else
            {
                cout<<z<<" "<<a-y+1;
            }
            break;
        }
    }
    return 0;
}
