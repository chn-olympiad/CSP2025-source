#include <bits/stdc++.h>
using namespace std;
int m,n,a[1000],b[100][100],r;
bool cmp(int a,int b){
return a>b;
}
int main ()
{
    freopen("seat.in","w",stdin);
    freopen("seat.out","r",stdout);
    int n,s;
    cin>>n;
    for(int i=1;i<=a*n;i++)
    {
        cin>>a[i];

    }
    sort(a+,a+n*1,cmp);










    return 0;
}
