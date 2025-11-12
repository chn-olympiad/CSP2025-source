/*
This is my second tour of csp-j/s.
Last year, I did very bad and got 190/100 pts at last.
If I cannot got s1=, I maybe AFO.

This year's cspj is as easy as last year. I even use just 20min AC T1&T2.

I can't trust that I use "niyuan" ((a / b) % mod = a % mod * (b ^ (p - 2)) % mod) correctly!
And I got anther 24pts on T4.
It's 10:44 now, I possible got 304pts(100 + 100 + 40 + 64) I have 1.25h left.

I find my English is really bad that I can't express many interesting things about this -j. 55555

Ok, it's 10:50 now, I have to fight with T3 now. (so tired... want to play florr(my florr name is ***csps2rp...   |*** is my name's first letter|))
Does T3 need ST or point tree? (n <= 5e5 be like O(nlogn))
Ok, it doesn't need those(I wrote them before cspj starts)
Why the kid sit beside me look at my code many times!!! angrey!!!
Can I give up? Ipossible get -j1= now. And I need rest for -s. (11:04, 56min left)
Let me check my code.
check over it's 11:21 now.
want to let my code show on "mi huo xing wei da shang"
I ate 5 pieces of chopsticks, but drank below 1L water(I brought above 2.5L)
Do define int long long will let me AFO?
Please don't become 0pts becouse of the define int long long!
30min left
just have a sleep zzz...
beybey
*/
#include <bits/stdc++.h>
#define int long long
#define x0 akcsp_j
#define x1 akcsp_s
#define y0 ak_noi
#define y1 ak_ioi
#define endl '\n'
#define hash my_hash
#define next my_next
#define LLMI LONG_LONG_MIN
#define LLMA LONG_LONG_MAX
using namespace std;
vector <char> a;
signed main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i ++)
    {
        if ('0' <= s[i] && s[i] <= '9')
        {
            a.push_back(s[i]);
        }
    }
    sort(a.begin(), a.end(), greater <int>());
    for (auto i : a)
    {
        cout << i;
    }
    cout << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
