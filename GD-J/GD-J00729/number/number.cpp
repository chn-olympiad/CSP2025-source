// 08:46 AC this problem

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int tong[256];
string str;

int main() 
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin.tie(0) -> sync_with_stdio(false);
    cin >> str;
    for(auto i:str)
        tong[i]++;
    for(char i='9';i>='0';i--)
        while(tong[i]--) putchar(i);
    return 0;
}

/***
 * My English is too bad :)
 * So use Chinglish!
 * 
 *******************************
 *
 * After getting 280pts (1=) in CSP-J 2024 as a grade-6 student,
 * CCF does not let the student below 12 years old join in CSP.
 * But I'm in junior high now, and I can join again :)
 *
 * The target for me in CSP 2025 is get high score in J,
 * and try to get 1= in S, but it is difficult for me to AC T2 in S.
 * I can just using the intelligence of human and get more score.
 * CSP-S problems can be not sorted by their color,
 * Like BGPP, GGPP, BBBB, etc. (B=blue,G=green,P=purple)
 *
 * After saying these, let's look for J.
 * At first I just wanted to AC T1,T2,T3 and using human intelligence to get more score in T4.
 * Then I ACed T1,T2 quickly, and thought about T3.
 * After using my brain for about 15 minute, and passed lots of solution,
 * I know how to do it.
 *
 * And when I saw D (T4), I was surprise.
 * It is easy to understand, and I think it is easier than T3.
 * What the f**k??? I use 15 second to get the sulution for T4...
 * (I think T4 is yellow, because it looks easy.)
 * Then I passed all the big examples of T4.
 *
 * And then, I think, the 1= score will be higher than the others before.
 * Because the problems are easier than before, and there was no pupil in the contest,
 * The 1= score will be higher, I don't know can it be 300+, but it will be 270+.
 * LOL.
 * 
 * But I have one classmate, he is a very JUUUUUUUUU JUUUUUUUUU_LAO (Chinese).
 * He said, he has percents to going to be AFOed if he doesn't got sqrt(6)...
 * How JUUUUUUUU he was??!
 *
 * Luogu UID 1439381.
 * Write this YOUJI from 09:59 to 10:27.
*/