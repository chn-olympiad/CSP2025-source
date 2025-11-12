#include<bits/stdc++.h>
using namespace std;

long long a[1000000],b[1000000];

int main()
{
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);

    int n,m;
    cin >> n >> m;
    
    for(int i=1;i<=n*m;i++)
    {
        cin >> a[i];
    }

    for(int i=1;i<=n*m-1;i++)
    {
        if(a[0]<a[i])
        {
            swap(a[0],a[i]);
        }
    }

    for
}