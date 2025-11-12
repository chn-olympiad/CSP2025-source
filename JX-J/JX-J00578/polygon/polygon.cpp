#include <bits/stdc++.h>

#define MOD 998244353

int n;
int a[5010], ps[5010], f[5010];

int solve(int n, int got, int s, int maxx)
{
    if (n + got < 3)
        return 0;
    if (n == 0)
        return s > maxx * 2;
    else
        return (solve(n - 1, got + 1, s + a[n], std::max(maxx, a[n]))
            + solve(n - 1, got, s, maxx)) % MOD;
}

int main()
{
    std::ios::sync_with_stdio(false);
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];

    std::sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i)
        ps[i] = ps[i - 1] + a[i];

    if (ps[n] == n)
    {
        int ans = 1, tmp = n * (n + 1) / 2;
        while (n--)
            ans = (ans << 1) % MOD;
        ans -= tmp;
        if (ans <= 0)
            ans += MOD;
        std::cout << ans;
    }
    else
        std::cout << (solve(n, 0, 0, -1) % MOD);

    return 0;
}

/*
journey diary

//freopen() just drawing visitors =D

7:4x
arrived =Ds
prepare's not enough =\ bu'an desu
test'll begin at 8:30 -_-
so i wrote a template and a part of the diary =P
then started the boooooorrrriing and loooooonng waiting *da'ha'qian*

8:0x
toilet.
(it's so normal that i put a '.' with bored me.)

8:1x
notice myself =C %$?&!...
-Unless you use long long, you'll see the God.
(when i finished reading all problems, i find i don't need long long)
-If there's little time, you can solve it bravely by making the table or fucking bao'li algorithm to make the qi'ji.

8:2x
i've been Grade 9 already
maybe i'll afk after this or maybe not.

hope Turing the Greatest God of Computer will bless me
hope Von Nuo'yi'man the Greatest God of Electric Computer will bless me

sro sro sro sro Turing orz orz orz orz

(meaningless hopes)

8:57
solved the 1st problem
EZ

9:25
solved the 2nd problem
thinking is ez
coding isn't very ez
feel very good
i think my state is fine

9:53
maybe i solved the 3rd problem
i used an O(n^2) algorithm (actually T( n+(n^2+n)/2 ))
i don't think i'll pass the last 4 point
which has n <= 200000 and 500000

btw, long live the pre-sum =D um, i mean qian'zhui'he

10:07
started reading the problem
i know that i'll TLE when i see 'mod 9,9824,4353'

10:15
i used pre-sum
no other idea

10:23
i think i can only cheat scores =(

10:42
gave up =(
hope i can pass as more as possible
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
don't count it
just 100 =D

11:2x
upload system boomed

11:36
system fixed
now i'm going to reupload
*/
