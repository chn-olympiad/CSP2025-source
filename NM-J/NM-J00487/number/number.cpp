#including <iostream>
using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    double a[1000000],s[10001];
    for (int i = 0;i <= 1000000;i++)
    {
        cin >> a[i];
        if (s[i] % 1 == 0)
        {
            s[i] = a[i];
        }
        else
        {
            continue;
        }
        for (int j = 0;j <= 10001;j++)
        {
            if (s[i] > s[i - 1])
            {
                cout << s[i];
            }
        }
    }
    return 0;
}
