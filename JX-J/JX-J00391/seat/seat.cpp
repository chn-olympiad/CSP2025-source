#include <bits/stdc++.h>
using namespace std;
int n,m,a[110];
int main()
{
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    int r=a[1],q=0;
    for(int i=2;i<=n*m;i++)
    {
        cin>>a[i];
        if(a[i]>r)
        {
            q++;
        }
    }
    int nr=1,mr=1,f=1;
    while(q>0)
    {
        q--;
        nr+=f;
        if(nr%n==0)
        {
            q-=2;
            mr++;
            f*=(-1);
            nr+=f;
        }
    }
    cout<<mr<<" "<<nr<<endl;
    return 0;
}
