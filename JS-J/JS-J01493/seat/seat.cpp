#include<bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int arr;
    cin >> arr;
    for(int i=2;i<=n*m;i++)
    {
        cin >> a[i];
    }
    a[1]=arr;
    sort(a+1,a+n*m+1);
    int numm=1;
    while(a[numm]!=arr) numm++;
    numm=n*m-numm+1;
    int lie,hang;
    if(numm%n==0)
    {
        lie=numm/n;
        if(lie%2==1) hang=n;
        else hang=1;
        cout << lie << " " << hang;
    }
    else
    {
        lie=numm/n+1;
        if(lie%2==1) hang=numm%n;
        else hang=n-numm%n+1;
        cout << lie << " " << hang;
    }
    return 0;
}
