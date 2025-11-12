#include <bits/stdc++.h>

using namespace std;
int n, m, a[100];

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m; //n hang m lie
    for(int i = 1; i <= n * m; i++) cin >> a[i];
    int x = a[1];
    sort(a + 1, a + (n * m) + 1, cmp);

    int xn = 1, xm = 1; // lie hang ans
    bool op = false; //false: xia  true: shang
    for(int i = 1; ; i++)
    {

        if(a[i] == x)
        {
            cout << xn << " " << xm << endl;
            break;
        }
        else
        {
            if(xm == n && op == false)
            {
                xn++;
                op = true;
            }
            else if(xm == 1 && op == true)
            {
                xn++;
                op = false;
            }
            else if(op == true) xm--;
            else if(op == false) xm++;
        }
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
