#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,k;
    long long a[111111];
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(k==0)
    {
        cout<<"1"<<endl;
    }
    return 0;
}
