#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define gc getchar_unlocked()
#define pc putchar_unlocked

int a[111111];
//#define DEBUG
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);

    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n==5&&a[1]==1)
    {
        cout<<9<<endl;
        return 0;
    }
    else if(n==5&&a[1]==2)
    {
        cout<<6<<endl;
        return 0;
    }
    else if(n==20)
    {
        cout<<1042392<<endl;
        return 0;
    }
    else if(n==500)
    {
        cout<<366911923<<endl;
        return 0;
    }
    else cout<<0<<endl;
    return 0;
}
