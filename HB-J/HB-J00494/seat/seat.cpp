#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin>>n>>m;
    int a[200];
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    int x=a[0];
    sort(a,a+n*m,greater<int>());
    int g=lower_bound(a,a+n*m,x,greater<int>())-a;
    int c=g/n;
    int r=c%2?((n-1)-g%n):g%n;
    cout<<c+1<<' '<<r+1;
    fclose(stdin);
    fclose(stdout);
    /*
    ← ←
     ↝
    */
    return 0;
}
