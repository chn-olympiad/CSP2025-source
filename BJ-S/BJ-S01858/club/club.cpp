#include <bits/stdc++.h>
using namespace std;

long long T, n, finans;
priority_queue <long long> qa, qb, qc;

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while(T--)
    {
        finans = 0;
        while(!qa.empty())qa.pop();
        while(!qb.empty())qb.pop();
        while(!qc.empty())qc.pop();
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            if(a >= max(b, c))
            {
                finans += a;
                qa.push(max(b - a, c - a));
            }
            else if(b >= max(a, c))
            {
                finans += b;
                qb.push(max(a - b, c - b));
            }
            else
            {
                finans += c;
                qc.push(max(a - c, b - c));
            }
        }
        n /= 2;
        while((int)qa.size() > n)
        {
            finans += qa.top();
            qa.pop();
        }
        while((int)qb.size() > n)
        {
            finans += qb.top();
            qb.pop();
        }
        while((int)qc.size() > n)
        {
            finans += qc.top();
            qc.pop();
        }
        cout << finans << "\n";
    }
    return 0;
}