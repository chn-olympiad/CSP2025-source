#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

struct member
{
    int a1, a2, a3;
    int m1, m2, m3;
};

bool cmp1 (member a, member b)
{
    if (a.m1 != b.m1)
        return a.m1 > b.m1;
    if (a.m2 != b.m2)
        return a.m2 > b.m2;
    return a.m3 > b.m3;
}

bool cmp2 (member a, member b)
{
    if (a.m2 != b.m2)
        return a.m2 > b.m2;
    return a.m3 > b.m3;
}

bool cmp3 (member a, member b)
{
    return a.m3 > b.m3;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<member> mem(n);
        for (int i = 0; i < n; i++)
        {
            cin >> mem[i].a1 >> mem[i].a2 >> mem[i].a3;
            int aaaaa[3] = {mem[i].a1, mem[i].a2, mem[i].a3};
            sort(aaaaa, aaaaa + 3, greater<int> ());
            mem[i].m1 = aaaaa[0]; mem[i].m2 = aaaaa[1]; mem[i].m3 = aaaaa[2];
        }
        sort(mem.begin(), mem.end(), cmp1);
        int sum = 0;
        int acnt[3] = {0};
        for (int i = 0; i < mem.size(); i++)
        {
            if (mem[i].m1 == mem[i].a1 && acnt[0] < n / 2)
            {
                acnt[0]++;
                sum += mem[i].m1;
                mem.erase(mem.begin() + i--);
            }
            else if (mem[i].m1 == mem[i].a2 && acnt[1] < n / 2)
            {
                acnt[1]++;
                sum += mem[i].m1;
                mem.erase(mem.begin() + i--);
            }
            else if (mem[i].m1 == mem[i].a3 && acnt[2] < n / 2)
            {
                acnt[2]++;
                sum += mem[i].m1;
                mem.erase(mem.begin() + i--);
            }
        }
        sort(mem.begin(), mem.end(), cmp2);
        for (int i = 0; i < mem.size(); i++)
        {
            if (mem[i].m2 == mem[i].a1 && acnt[0] < n / 2)
            {
                acnt[0]++;
                sum += mem[i].m2;
                mem.erase(mem.begin() + i--);
            }
            else if (mem[i].m2 == mem[i].a2 && acnt[1] < n / 2)
            {
                acnt[1]++;
                sum += mem[i].m2;
                mem.erase(mem.begin() + i--);
            }
            else if (mem[i].m2 == mem[i].a3 && acnt[2] < n / 2)
            {
                acnt[2]++;
                sum += mem[i].m2;
                mem.erase(mem.begin() + i--);
            }
        }
        sort(mem.begin(), mem.end(), cmp3);
        for (int i = 0; i < mem.size(); i++)
        {
            if (mem[i].m3 == mem[i].a1 && acnt[0] < n / 2)
            {
                acnt[0]++;
                sum += mem[i].m3;
                mem.erase(mem.begin() + i--);
            }
            else if (mem[i].m3 == mem[i].a2 && acnt[1] < n / 2)
            {
                acnt[1]++;
                sum += mem[i].m3;
                mem.erase(mem.begin() + i--);
            }
            else if (mem[i].m3 == mem[i].a3 && acnt[2] < n / 2)
            {
                acnt[2]++;
                sum += mem[i].m3;
                mem.erase(mem.begin() + i--);
            }
        }
        cout << sum << '\n';
    }
    return 0;
}
