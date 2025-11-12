#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

int a[110];

void run()
{
    int n,m;
    cin>>n>>m;
    function<int(int,int)> cnt1=[=](int a,int b)
    {
        return a*n+b;
    };
    function<int(int,int)> cnt2=[=](int a,int b)
    {
        return a*n+n-b-1;
    };
    for(int i=0;i<n*m;i++) cin>>a[i];
    int re=a[0];
    sort(a,a+n*m,[](int a,int b){return a>b;});
    for(int i=0;i<m;i++)
    {
        if(i&1)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(a[cnt2(i,j)]==re)
                {
                    cout<<i+1<<" "<<j+1;
                    return;
                }
            }
        }
        else
        {
            for(int j=0;j<n;j++)
            {
                if(a[cnt1(i,j)]==re)
                {
                    cout<<i+1<<" "<<j+1;
                    return;
                }
            }
        }
    }
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    t=1;
    while(t--)
    {
        run();
        cout<<"\n";
    }

    return 0;
}
