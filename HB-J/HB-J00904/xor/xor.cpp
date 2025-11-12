#include<iostream>

using namespace std;

int xr(int a, int b)
{
    return (a | b) - (a & b);
}

int n, k;
int a[600000];
int t[600000];
int cnt=0;

int xrt(int l, int b)
{
    if(l == b)
    {
        return a[l];
    }
    else
    {
        if(l == 0)
        {
            return t[b];
        }
        else
        {
            return xr(t[b], t[l-1]);
        }
    }
}

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    t[0]=a[0];
    for(int i = 1; i < n; i++)
    {
        t[i] = xr(t[i - 1], a[i]);
    }

    int s = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = s; j <= i; j++)
        {
            if(xrt(j, i) == k)
            {
                cnt++;
                s = i+1;
                //cout << j+1 << ' ' << i+1;
                break;
            }
        }
    }

    cout << cnt;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
