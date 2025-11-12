#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N];
bool cmp(int a,int b){return a>b;}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int t=a[1];
    sort(a+1,a+n*m+1,cmp);
    int w=0;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==t)
        {
            w=i;
            break;
        }
    }
    int r=ceil(w*1.0/n),c;
    if(r%2==0) c=n-w%n+1;
    else
    {
        c=w%n;
        if(c==0) c=n;
    }
    cout<<r<<" "<<c;
    return 0;
}
