#include<bits/stdc++.h>
using namespace std;
const int N=20;
int n,m,b,k,a;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>b;
    for(int i=2;i<=n*m;i++)
    cin>>a,k+=(a>b? 1:0);
    cout<<k/n+1<<' '<<(((k/n)&1)?n-k%n:k%n+1);
    return 0;
}