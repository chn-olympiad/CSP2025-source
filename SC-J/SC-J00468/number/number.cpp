#include <cstdio>
#if __linux__
#define ge getchar_unlocked
#define pu putchar_unlocked
#else
#define ge getchar
#define pu putchar
#endif
typedef long long ll;
#define fileio(i) freopen(i".in", "r", stdin), freopen(i".out", "w", stdout)
int n, cnt[12];
char ch;
int main(){
    fileio("number");
    while ((ch=ge())!='\n'&&ch!=EOF) 
        if ('0'<=ch&&ch<='9')
            ++cnt[ch-'0'];
    for (int i=9;i>=0;i--)
        while (cnt[i]--)
            pu(i+'0');
    return 0;
}
/*
# CSP-J 2025 Solution (during the exam)

My English is not so good. So pardon me for my mistakes.

## T1 number
Take out all the number characters, sort them from the big one to the small one. Then output them directly character by character.

## T2 seat
First calc the rank of Mr.R's score. You can use `std::sort` and `std::lower_bound` to do this thing. Then calc the row number by dividing the rank by n. The rest part is the line number. If the row number is even, the line number should be reversed(`y=n+1-y`). Please pay attention to the result of dividing: you need to let the rank decrease 1 first before the dividing. Then the result should increase 1. By doing this way, you can get the correct result.

## T3 xor
First, you need to pay attention to that the xor sum of a segment [l, r] could be discribe as `s[l-1]^s[r]`, while `s[i]` score the xor sum of the segment [1, i]. Then, by reminding the place of the `s[i]` or `s[i]^k`, you can easily get the segments which its xor sum is k. Then it becomes a very tradtional Tanxin problem: choose the segments as more as possible to make them don't have any part in common with each other. Sort the segments by the rightest point. If now the segment's leftest point is bigger than the rightest point of the chosen segments, you can choose this segment. Get the answer by counting the chosen segments.

## T4 polygon
It's easy to find this problem has to do with Dynamic Programming. Sort the numbers first. If we want a number `a[i]` to be the biggest, we need to find the ways of choosing numbers which smaller than `a[i]` to make their sum bigger than `a[i]`. It is too difficult, so we can try to calc the ways of choosing numbers which smaller than `a[i]` to make their sum smaller than `a[i]`. Then we can design DP: `f[i][j]` shows the number of ways to choose the numbers from `a[1]` to `a[i]` and their sum equals to `j`. It is an easy 01-backpack DP problem. Let `g[i]` equals to the sum from `f[i-1][0]` to `f[i-1][a[i]]`. If we let `a[i]` is the biggest number among the chosen numbers, the answer will be $2^{i-1}-g[i]$. The final answer is calced by adding all the answers of letting `a[i]` is the biggest number among the chosen numbers.
*/