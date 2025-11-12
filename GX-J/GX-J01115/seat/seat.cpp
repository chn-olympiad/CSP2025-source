#include <iostream>
using namespace std;
int s[10000000];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x=0,h=1,l=1;
    cin>>n>>m;
    x=n*m;
    for(int i=1;i<=x;i++)
        cin>>s[i];
    for(int i=2;i<=x;i++)
    {
        if(s[1]<s[i])
          {
              if(l%2==0)
              {
                  if(h>1)
                        h--;
                  else
                  {
                       if(l<m)
                        l++;
                  }

              }
            else
                if(h<n)
                    h++;
                else
                {
                     if(l<m)
                    l++;

                }

          }
    }
    cout<<l<<" "<<h;
    return 0;
}
