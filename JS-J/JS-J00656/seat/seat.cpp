#include<bits/stdc++.h>
#define N 15
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
int n,m,a[110],i=1,j=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int s=n*m;
    cin>>a[1];
    int me=a[1];
    for(int i=2;i<=s;i++)
        cin>>a[i];
    sort(a+1,a+s+1,greater<int>());
    int k=0;
    while(a[++k]!=me&&k<=s);
    int id=1,h=1;
    if(k%n==0)  j=k/n;
    else j=k/n+1;
    if(j%2) i=k%n;
    else
    {
        if(k%n==0)  i=1;
        else i=n+1-k%n;
    }
    cout<<j<<" "<<i<<endl;
    return 0;
}
