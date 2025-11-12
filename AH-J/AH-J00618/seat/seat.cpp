#include <bits/stdc++.h>

using namespace std;

int n,m,s;
int a[100101],b[111][110];
bool self(int a,int b){return a>b?true:false;}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int k=1;k<=n*m;k++)
    {
        cin >> a[k];
    }
    int tmp=a[1];
    sort(a+1,a+n*m+1,self);
    for(int k=1;k<=m*n;k++)
    {
        if(a[k]==tmp){s=k;break;}
    }
    int d=(s-1)/n;
    if(d%2==1)
        cout << d+1 << " " << (d+1)*n-s+1;
    else
        cout << d+1 << " " << s-d*n;
    return 0;
}
