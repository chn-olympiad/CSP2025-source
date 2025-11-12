#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n,k,sum;
int ans;
int a[N];
bool used[N];
vector<int> v;
vector<int> v2;
vector<int> v3;
bool f(int l)
{
    for(int i = 0; i <= 20; i++)
    {
        if(l == pow(2, i))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i] == k)
        {
            ans++;
            used[i] = true;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(used[i])
        {
            sum = 0;
            continue;
        }
        else
        {
            if(f(a[i]))
            {
                sum += a[i];
            }
            else
            {
                int sum1 = sum;
                int temp = a[i];
                while(sum1 || temp)
                {
                    v.push_back(sum1 % 2);
                    v2.push_back(temp % 2);
                    temp /= 2;
                    sum1 /= 2;
                }
                for(int j = max(v.size(), v2.size()); j >= 1; j--)
                {
                    if(v[i] + v2[i] == 2)
                        v3.push_back(1);
                    else
                        v3.push_back(v[i] + v2[i]);
                }
                sum = 0;
                for(int j = 1; j <= v3.size(); j++)
                {
                    sum += pow(2, j-1);
                }
            }
            if(sum == k)
            {
                ans++;
                sum = 0;
            }
        }
    }
    cout << ans;
    return 0;
}
