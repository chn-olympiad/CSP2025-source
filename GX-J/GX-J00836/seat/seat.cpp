#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],w=1,z=1;
int main()
{
freopen("seat.in","r",stdin);
freopen( "seat.out", "w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
int te=1;
cin>>n,m;
for (int i=1;i<=n;i++)
{
    for(int j=1;i<=m;j++)
    {
        cin>>a[te];
        if(a[0]<a[te])
        {
            z++;
            te++;
        }
        else if(a[0]>a[te])
            {
                return 0;
            }
    }
    if(z%m==0)
    {
        w++;
    }

}
cout<<w<<" "<<z;
return 0;
}
