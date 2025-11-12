#include <bits/stdc++.h>

using namespace std;

long long n,a[100005][5], x, y, z, s;
long long b[100005];

int pd(long long a, long long b, long long c)
{

    if (a > b and a > c)  return 1;  // go 1
    if (b > a and b > c)  return 2;  // go 2
    if (c > a and c > b)  return 3;  // go 3
    if (a == b and a > c) return 4;  // go 1 or 2
    if (a > b and a == c) return 5;  // go 1 or 3
    if (b > a and b == c) return 6;  // go 2 or 3
    if (a == b and a == c) return 7;  // go 1 or 2 or 3(he can go anywhere)
    return 0;
}


void Main()
{

    //fuck, now the problem is how to dp to make it biggest, I only can tanxin, I am trying to bianli to try getting score.
    //But I don't have mind.I want to give up,teacher.Although I spend all time solving it, I am failed. I am so sorry. ----18:12

    //no, no, no! how did huangweibo do in the last exam? he got two, but now I only get zero! And I don't know how to use these require----18:22
    x = 0;
    y = 0;
    z = 0;
    s = 0;

    cin >> n;
    bool f = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        if (a[i][1] != 0 or a[i][2] != 0)
        {
            f = 1;
        }
    }
    if (f == 0)
    {
        for (int i = 0; i < n; i++)
        {
            b[i] = a[i][0];
        }
        sort(b, b + n);
        long long i = 0, p = n / 2;
        while (i < p)
        {
            i++;
            n--;
            s += b[n];
        }
        cout << s << endl;
        return;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int zt = pd(a[i][0], a[i][1], a[i][2]);
        int ax = a[i][0];
        int ay = a[i][1];
        int az = a[i][2];
        // if (zt == 0) cout << "Fuck!\n";
        if (zt == 1)
        {
            //cout << "FUCK1\n";
            if (x < n / 2) // Maybe there is a problem!!!!
            {
                x++;
                s += ax;
            }
            else
            {
                if (a[i][1] >= a[i][2] and y < n / 2) // Maybe there is a problem!!!!
                {
                    y++;
                    s += ay;
                    //cout << ay << endl;
                }
                else
                {
                    z++;
                    s += az;
                }
            }
        }
        if (zt == 2)
        {
            //cout << "FUCK2\n";
            if (y < n / 2) // Maybe there is a problem!!!!
            {
                y++;
                s += ay;
            }
            else
            {
                if (a[i][0] >= a[i][2] and x < n / 2)  // Maybe there is a problem!!!!
                {
                    x++;
                    s += ax;
                }
                else
                {
                    z++;
                    s += az;
                }
            }
        }
        if (zt == 3)
        {
            //cout << "FUCK3\n";
            if (z < n / 2)
            {
                z++;
                s += az;
            }
            else
            {
                if (a[i][0] >= a[i][1] and x < n / 2)
                {
                    x++;
                    s += ax;
                }
                else
                {
                    y++;
                    s += ay;
                }
            }
        }
        if (zt == 4)  // a[i] wants to go to 1 and 2
        {
            //cout << "FUCK4\n";
            /*
            x > y
            x < y
            x == y
            */
            int t = pd(x, y, -1);
            if (t == 1) // the number of 1 is more than 2(x > y)
            {
                if (y < n / 2)
                {
                    y++;
                    s += ay;
                }
                else    // now 1 > 2 > n / 2 > 3
                {
                    z++;
                    s += az;
                }
            }
            if (t == 2) // the number of 1 is less than 2(x < y)
            {
                if (x < n / 2)
                {
                    x++;
                    s += ax;
                }
                else    // now 2 > 1 > n / 2 > 3
                {
                    z++;
                    s += az;
                }
            }
            if (t == 4) //the number of 1 is as same as 2 and the a[i] wants to go 1 and 2(x == y), now the 1(2) is less than n / 2(1 == 2 < n / 2)
            {
                x++;
                s += ax;
            }
        }
        if (zt == 5) // a[i] wants to go to 1 and 3
        {
            //cout << "FUCK5\n";
            /*
            x > z
            x < z
            x == z
            */
            int t = pd(x, z, -1);
            if (t == 1) // the number of 1 is more than 3(x > z)
            {
                if (z < n / 2)
                {
                    z++;
                    s += az;
                }
                else    // now 1 > 3 > n / 2 > 2
                {
                    y++;
                    s += ay;
                }
            }
            if (t == 2) // the number of 1 is less than 3(x < z)
            {
                if (x < n / 2)
                {
                    x++;
                    s += ax;
                }
                else    // now 3 > 1 > n / 2 > 2
                {
                    y++;
                    s += ay;
                }
            }
            if (t == 4) //the number of 1 is as same as 3 and the a[i] wants to go 1 and 3(x == z), now the 1(3) is less than n / 2(1 == 3 < n / 2)
            {
                x++;
                s += az;
            }
        }
        if (zt == 6)
        {
            //cout << "FUCK6\n";
            /*
            y > z
            y < z
            y == z
            */
            int t = pd(y, z, -1);
            if (t == 1) // the number of 2 is more than 3(y > z)
            {
                if (z < n / 2)
                {
                    z++;
                    s += az;
                }
                else    // now 2 > 3 > n / 2 > 1
                {
                    x++;
                    s += ax;
                }
            }
            if (t == 2) // the number of 2 is less than 3(y < z)
            {
                if (y < n / 2)
                {
                    y++;
                    s += ay;
                }
                else    // now 3 > 2 > n / 2 > 1
                {
                    x++;
                    s += ax;
                }
            }
            if (t == 4) //the number of 2 is as same as 3 and the a[i] wants to go 2 and 3(y == z), now the 2(3) is less than n / 2(2 == 3 < n / 2)
            {
                y++;
                s += ay;
            }
        }
        if (zt == 7)
        {
            //cout << "FUCK7\n";

            if (y > x and z > x)
            {
                x++;
                s += ax;
            }
            if (x > y and z > y)
            {
                y++;
                s += ay;
            }
            if (x > z and y > z)
            {
                z++;
                s += az;
            }
            if (x == y and y == z)
            {
                x++;
                s += ax;
            }
        }
    }
    //printf("x = %lld, y = %lld, z = %lld\n", x, y, z);
    cout << s << endl;


    return;
}


int main()
{

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int t;
    cin >> t;
    while (t--)
    {
        Main();
    }


    return 0;
}
