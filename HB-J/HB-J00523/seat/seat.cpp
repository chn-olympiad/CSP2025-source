#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int a[N];
int n,m,x;
bool cmp(int a,int b)
{
    return a>b;
}
void solve()
{
    cin>>n>>m>>x;
    a[0]=x;
    for(int i=1;i<n*m;i++)
    {
        cin>>a[i];
    }
    sort(a,a+(n*m),cmp);
    int k=0;
    for(int i=0;i<n*m;i++)
    {
        if(a[i]==x)
        {
            k=i+1;
            break;
        }
    }
    int tp=1;
    while(k>n)
    {
        k-=n;
        tp++;
    }
    cout<<tp<<' ';
    if(tp%2==0)cout<<n-k+1;
    else cout<<k;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int T=1;
    while(T--)
    {
        solve();
    }
    return 0;
}
//3 5 6 100 97 96 95 94 93 92 10 9 8 7 5 4 3

