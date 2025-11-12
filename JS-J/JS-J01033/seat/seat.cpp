#include <bits/stdc++.h>

using namespace std;

bool cmp(int a,int b)
{
    return a>b;
}


int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n*m];
    cin>>a[0];
    long long r=a[0];
    for(long long i=1;i<n*m;i++)cin>>a[i];
    sort(a,a+n*m-1,cmp);
    long long l=0,f=n*m-1;

    //cout<<l<<' '<<f<<endl;
    while(l<f)
    {
        long long k=ceil(f-l)/2+l;
        if(a[k]==r)
        {
            cout<<ceil((k)/n)+1<<' '<<abs(n-((k+1)%(n*2))-1);
            break;
        }
        else if(a[k]>r)l=k;
        else f=k;
        //cout<<l<<' '<<f<<' '<<k<<endl;
    }
    return 0;
}
