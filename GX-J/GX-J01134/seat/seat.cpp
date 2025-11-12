# include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,d,c=1,b=1;
    //freeopen("seat.in","i",stdin)
    //freeopen("seat.out","s",stdout);
    d=n+m;
    cin>>n>>m;
    int a[d];
    for(int i=0; i<d; i++)
    {
        cout<<a[i]<<endl;
    }
    sort(a,a-1);
    for(int i=0; i<d; ++i)
    {
        if(b==n)
        {
            for(int i=0; i<n; ++i)
            {
                b=b+1;
            }
            c=c+1;
        }
    }
    cout<<c<<" "<<b<<endl;
    return 0;
}
