#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int x,int y)
{
    return x > y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int sum = n * m;
    for(int i = 1; i<= sum;i++)
    {
        cin >> a[i];
    }
    int r= a[1];
    sort(a+1,a+1+sum,cmp);
    for(int i = 1; i <= sum; i++)
    {
        if(a[i] == r)
        {
            r = i;
            break;
        }
    }
    int h= 0,hh =0;
    if(r % m == 0)
    {
        h = 1;
        hh = r / m;
    }
    else
    {
        h = r % m;
        hh = r /m +1;
    }
    int l = 0;
    if(hh % 2 ==0)
    {
        l = m + 1 - h;
    }
    else
    {
        l = h;
    }
    cout << hh << ' ' << l;
    return 0;
}
