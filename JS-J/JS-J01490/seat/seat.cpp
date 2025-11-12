#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,l[105];
    cin>>n>>m;
    for(int i=0;i<n*m;i++) cin>>l[i];
    int my=l[0];
    sort(l,l+n*m);
    int x=0,y=0,sz=n*m-1;
    while(y<=m)
    {
        if(x==0)
        {
            for(int i=0;i<n;i++)
            {
                if(l[sz--]==my) cout<<x<<" "<<y;
                x++;
            }
        }
        if(x==n-1)
        {
            for(int i=0;i<n;i++)
            {
                if(l[sz--]==my) cout<<x<<" "<<y;
                x--;
            }
        }
        y++; 
    }
    return 0;
}