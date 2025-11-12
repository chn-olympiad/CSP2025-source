#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    int n,m,d,b=1,c=1;
    cin>>n>>m;
    d=m*n;
    int a[101];
    for(int i=0;i<d;i++){

        cin>>a[i];
    }
    //sort(a,a-1);
    for(int i=0;i<d;i++)
    {
    if(b!=n&&b!=1)
        {
            for(int i=2;i<n;i++)
            {
                b++;
            }
    }

    if(b=n)
    {
        c=c+1;
        for(int i=n;i>1;i--)
        {
            b--;
        }
        }


    if(b=1)
    {
        c=c+1;
        for(int i=1;i<2;i++)
        {
            b++;
        }

    }
    }
    cout<<c-1<<" "<<b;
    return 0;
}
