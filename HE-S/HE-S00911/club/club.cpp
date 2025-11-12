#include <iostream>
using namespace std;
int a[100005],b[100005],c[100005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int m,n,k=0;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j]>>b[j]>>c[j];
            k+=max(max(a[j],b[j]),c[j]);
        }
        cout<<k<<endl;
        k=0;
    }
}
