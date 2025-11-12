#include<iostream>
#include<algorithm>

using namespace std;
const int MAXN = 5e5+7;
int n,k;
int a[MAXN];

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++)  cin>>a[i];
    if (a[1]^a[2]==k)
    {
        cout<<2<<endl;
        return 0;
    }
    else if (a[1]==k || a[2]==k)
    {
        cout<<1<<endl;
        return 0;
    }
    cout<<0<<endl;
    return 0;
}
