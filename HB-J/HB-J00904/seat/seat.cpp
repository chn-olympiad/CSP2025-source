#include<iostream>


using namespace std;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    int a[200], h, c = 0;
    cin >> n >> m;
    int to = n * m;
    for(int i = 0; i < to; i++)
    {
        cin >> a[i];
        if(i == 0)
        {
            h = a[i];
            c++;
        }
        else
        {
            if(a[i] > h)
            {
                c++;
            }
        }
    }
    int an1, an2;
    if(c % n == 0)
    {
        an1 = c / n;
        if(an1 % 2 == 1)
        {
            an2 = n;
        }
        else
        {
            an2 = 1;
        }
    }
    else
    {
        an1 = c / n + 1;
        if(an1 % 2 == 1)
        {
            an2 = c % n;
        }
        else
        {
            an2 = n + 1 - c % n;
        }
    }
    cout << an1 << ' ' << an2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
