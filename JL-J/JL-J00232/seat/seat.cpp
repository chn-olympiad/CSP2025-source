#include<bits/stdc++.h>
using namespace std;
int a[1000][1000],b[1000];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,sum,sum1=0,r,c;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            sum=a[0][0];
            if(sum<a[i][j])
            {
                sum1++;
            }
        }
    }
    r=sum1/n;
    c=sum1-n;
    cout<<r<<" "<<c<<endl;
    return 0;
}
