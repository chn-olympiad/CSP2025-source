#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,t,a[N],b[N],c[N],h,w1,w2;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.in","w",stdout);
    cin>>t;
    while(t--)
    {
    h=0;
    w1=0;
    w2=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];

        if((a[i]>b[i]||w2>=n/2)&&w1<n/2)
        {
        h+=a[i];
        w1++;
        //cout<<w1<<" "<<1<<endl;
        }
        if((b[i]>a[i]||w1>=n/2)&&w2<n/2)
        {
        h+=b[i];
        w2++;
        //cout<<w2<<" "<<2<<endl;
        }
    }
    cout<<h<<endl;
    }
    return 0;
}
