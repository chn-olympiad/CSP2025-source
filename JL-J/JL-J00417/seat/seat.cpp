#include <bits/stdc++.h>
using namespace std;
int n,m,s=0;
int p,q,c,o;
int a[11];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);



    cin>>n>>m;
    c=m*n;
    for (int i=0;i<c;i++)
    {
        cin>>a[i];
    }
    o=a[0];

    for (int i=0;i<c;i++)
    {

        if (o<a[i])
        {

            s=s+1;

        }
    }
    p=s/n;
    q=s%n;
    if (p%2==0)
    {
        cout<<p+1<<" "<<1+q;
    }
    else{
        cout<<p+1<<" "<<n-q;
    }

return 0;

}
