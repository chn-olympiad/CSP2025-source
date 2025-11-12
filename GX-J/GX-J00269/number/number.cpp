#include <bits/stdc++.h>
using namespace std;
int sum[100009],c=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    getline(cin,a);
    for(int i = 0;i<a.size();i++)
    {

        if(a[i] == '0')
        {
            c++;
            sum[c] = 0;

        }
        if(a[i] == '1')
        {
            c++;
            sum[c] = 1;
        }

        if(a[i] == '2')
        {
            c++;
            sum[c] = 2;

        }
        if(a[i] == '3')
        {
            c++;
            sum[c] = 3;

        }
        if(a[i] == '4')
        {
            c++;
            sum[c] = 4;

        }
        if(a[i] == '5')
        {
            c++;
            sum[c] = 5;

        }
        if(a[i] == '6')
        {
            c++;
            sum[c] = 6;

        }
        if(a[i] == '7')
        {
            c++;
            sum[c] = 7;

        }
        if(a[i] == '8')
        {
            c++;
            sum[c] = 8;

        }
        if(a[i] == '9')
        {
            c++;
            sum[c] = 9;

        }
    }
    for(int i = 1;i<=c-1;i++)
    {
        for(int j = 1;j<=c-1;j++)
        {
            if(sum[j] > sum[j+1])
            {
                swap(sum[j],sum[j+1]);
            }
        }
    }
    for(int i = c;i>=1;i--)
    {
        cout << sum[i];
    }

    return 0;
}
