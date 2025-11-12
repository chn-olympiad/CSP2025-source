#include <bits/stdc++.h>
using namespace std;
int n,m;
int cj[105],r,v;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n >> m;
    cin >> r;
    cj[1]=r;
    for(int i=2;i<=n*m;i++)
    {
        cin >> cj[i];
    }
    sort(cj+1,cj+n+1,cmp);
    int k=upper_bound(cj+1,cj+(n*m)+1,r)-cj;
    cout << k << endl;
    int c;
    if(k%n!=0)
    {
        c=k/n+1;
        if(c%2==0)
            v=n-k%n+1;
        else
            v=k%n;
    }
    else{
        c=k/n;
        v=n;
    }
    cout << c << " " << v;
    return 0;
}
