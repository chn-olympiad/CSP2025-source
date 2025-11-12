#include<bits/stdc++.h>
using namespace std;

int a[1005], n, m;


int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int jsq = 0;
    cin >> n>> m;
    for(int i = 1; i <=  n * m; i++)
        cin >> a[i];
    for(int  i = 2; i <= n * m; i++)
        if(a[i] > a[1]) jsq++;
    int k = jsq / 2 / n;
    jsq = jsq - (k * 2 * n) + 1;
    if(jsq <= n)
    {
        cout<< 2 * k + 1<< " "<< jsq;
    }
    else
    {
        cout<< 2 * k + 2<< " "<< 2 * n - jsq + 1;
    }
}
