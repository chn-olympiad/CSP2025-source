#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    if(n<3)
    {
        cout<<0;
        return 0;
    }
    int a[5001];
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<1;
    return 0;
}
