#include<bits/stdc++.h>
using namespace std;
int n,m,r,rseatnum = 1,rseat,rseatm,rseatn;
int score[110];
bool have[110];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= 100;i++)
    {
        have[i] = false;
    }
    for(int i = 1;i <= n * m;i++)
    {
        cin >> score[i];
        have[score[i]] = true;
    }
    r = score[1];
    for(int i = 100;i >= 1;i--)
    {
        if(have[i] == true && i == r)
        {
            rseat = rseatnum;
        }
        else if(have[i] == true)
        {
            rseatnum++;
        }
    }
    rseatm = rseat / n + 1;
    if(rseatm % 2 == 1)
    {
        rseatn = rseat % n;
    }
    else
    {
        rseatn = n - (rseat % n) + 1;
    }
    cout << rseatm << " " << rseatn;
    return 0;
}
