#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,e[105],x=1,f=0;
int y=1;
int main()
{
freopen("seat.in","r",stdin);

freopen("seat.out","w",stdout);
    cin>>a>>b;

    cin>>d;
    e[d]++;
    for(int i=1; i<a*b; i++)
    {
        cin>>c;
        e[c]++;
    }
    for(int i=100; i>=0; i--)
    {
        if(i!=0&&i!=d){
            f++;
        }
        if(i==d){
            x=f/b+1;
            y=f%b+1;
            cout<<x<<' '<<y;
            break;
        }

    }

    return 0;
}


