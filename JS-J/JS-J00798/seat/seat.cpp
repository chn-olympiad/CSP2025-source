#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int r,c;
    cin>>r>>c;
    int n=r*c;
    int a[101];
    for(int i=1;i<=n;i++) cin>>a[i];
    int cj=a[1];
    sort(a+1,a+n+1);

    int mingci;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==cj)
        {
        mingci=i;
        break;
        }
    }
    mingci=n+1-mingci;
    int j=(mingci/c)%2;
    if(mingci%c==0)
    {
        if(j==0)
        {
            cout<<mingci/c<<" "<<1;
            return 0;
        }
        else{
            cout<<mingci/c<<" "<<c;
            return 0;
        }
    }
    else{
        if(j==0)
        {
            cout<<(mingci/c)+1<<" "<<mingci%c;
            return 0;
        }
        else{
            cout<<(mingci/c)+1<<" "<<c+1-(mingci%c);
            return 0;
        }
    }
    return 0;
}
