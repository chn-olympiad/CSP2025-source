#include<bits/stdc++.h>
#define ll long long

using namespace std;
int a[110], n, m;
int R_seat;

bool cmp(int a, int b)
{

    return a > b;
}

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n * m; i++)
    {
        cin >> a[i];
    }

    R_seat = a[1];

    sort(a + 1, a + (n * m) + 1, cmp);
    //cout << R_seat;
    for(int i = 1; i <= n * m; i++)
    {

        if(a[i] == R_seat)
        {
            //cout << a[i];
            R_seat = i;
            break;
        }
        //cout << 0;
    }

    int n_R, m_R;
    if(R_seat % n != 0)
    {
        m_R = R_seat / n +1;
        if(m_R % 2 == 0)
        {
            n_R = n - (R_seat % n) + 1;
        }
        else
        {
            n_R = R_seat % n;
        }
    }
    else
    {
        m_R = R_seat / n;
        if(m_R % 2 == 0)
        {
            n_R = 1;
        }
        else
        {
            n_R = n;
        }
    }

    cout << m_R << ' ' << n_R;
    return 0;
}
/**/
