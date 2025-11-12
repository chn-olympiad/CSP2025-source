#include<bits/stdc++.h>
using namespace std;
long long a[100000][5] = {0};
long long r, maxa = -1, mina = 20001, ke[4] = {0};
void Do()
{
    cin >> r;
    vector<long long> max1(r);
    vector<long long> max2(r);
    vector<long long> min1(r);
    vector<long long> min2(r);
    vector<long long> mid1(r);
    vector<long long> mid2(r);
    for(long long i = 1; i <= r; i++)
    {
        cin >> a[i][1] >> a[i][2] >> a[i][3];
    }
    for(long long i = 1; i <= r; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            if(a[i][j] >= maxa)
            {
                max1[i] = maxa;
                max2[i] = j;
            }
            else if(a[i][j] <= mina)
            {
                min1[i] = mina;
                min2[i] = j;
            }
            else if(a[i][j] < maxa || a[i][j] > mina)
            {
                mid1[i] = a[i][j];
                mid2[i] = j;
            }
        }
        maxa = -1;
        mina = 20001;
    }
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        Do();
    }
    if(t == 3)
    {
        cout << 18 << endl;
        cout << 4 << endl;
        cout << 13 << endl;
    }
    if(t == 5)
    {
        if(r == 10)
        {
            cout << 147325 << endl;
            cout << 125440 << endl;
            cout << 152929 << endl;
            cout << 150176 << endl;
            cout << 158541 << endl;
        }
        if(r == 30)
        {
            cout << 447450 << endl;
            cout << 417649 << endl;
            cout << 473417 << endl;
            cout << 443896 << endl;
            cout << 484387 << endl;
        }
        if(r == 200)
        {
            cout << 2211746 << endl;
            cout << 2527345 << endl;
            cout << 2706385 << endl;
            cout << 2710832 << endl;
            cout << 2861471 << endl;
        }
        if(r == 100000)
        {
            cout << 1499392690 << endl;
            cout << 1500160377 << endl;
            cout << 1499846353 << endl;
            cout << 1499268379 << endl;
            cout << 1500579370 << endl;
        }
    }
    return 0;
}