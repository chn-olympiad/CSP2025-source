#include <bits/stdc++.h>
using namespace std;
long long pos = 0;
priority_queue <long long> pq;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(0);
    string a;
    cin >> a;
    for(long long i = 0; i < a.size(); i++)
    {
        if(isdigit(a[i]))
        {
            long long num = a[i] - '0';
            pq.push(num);
        }
    }
    while(!pq.empty())
    {
        cout << pq.top();
        pq.pop();
    }
    cout << '\n';
    return 0;
}
//expected 100pts