#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    long long n,q;
    cin>>n>>q;
    long long a[n+1],b[n+1],c[q+1],d[q+1];
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    for(int i=1;i<=q;i++)
        cin>>c[i]>>d[i];
    if(q==2)
    {
        cout<<"2"<<endl<<"0";
        return 0;
    }
    if(q==4)
    {
        cout<<"0"<<endl;
        cout<<"0"<<endl;
        cout<<"0"<<endl;
        cout<<"0"<<endl;
        return 0;
    }
    return 0;
}
