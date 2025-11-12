#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat","w",stdin);
    freopen("seat","r",stdout);
    int n,m,hang,lie;
    int a[105];
    int a1,j=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(i==1)
        {
            a1=a[i];
        }
    }
    sort(a+1,a+n*m+1);
    for(int i=n*m;i>=1;i--)
    {
        if(a1==a[i])
        {
            hang=j%(n*2);
            if(hang>n)
            {
                hang=hang-n;
                hang=n-hang+1;
            }
            if(j<=n)
                lie=1;
            else
                lie=j/n+1;
            cout<<lie<<" "<<hang;
            return 0;
        }
        j++;
    }
}
