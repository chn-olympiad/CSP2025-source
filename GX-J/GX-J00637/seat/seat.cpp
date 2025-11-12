#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >>n>>m;
    int num[n*m];
    int ming;
    for(int i=0;i<=n*m-1;i++)
    {
        cin >>num[i];
    }
    ming=num[0];
    sort(num,num+n*m);
    for(int i=0;i<=n*m-1;i++)
    {
        if(num[i]==ming)
        {
            ming=n*m-i;
            break;
        }
    }
    if(ming%n==0)
    {
        cout <<ming/n<<' ';
        if((ming/n)%2)
        {
            cout << n;
        }
        else
        {
            cout << 1;
        }
        return 0;
    }
    cout <<ming/n+1<<' ';
    if((ming/n+1)%2)
    {
        cout <<ming%n;
        return 0;
    }
    cout <<n-(ming%n)-1;
    return 0;
}
