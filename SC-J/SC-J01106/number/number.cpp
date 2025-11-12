#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1000005;
string S;
int n,m;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> S;
	m = S.size();
	for(int i = 0;i < m;i++)
		if(S[i] >= '0' && S[i] <= '9')	a[++n] = S[i];
	sort(a+1,a+1+n);
	for(int i = n;i;i--)	putchar(a[i]);
	putchar('\n');
	fclose(stdin);
	fclose(stdout);
	return 0;
}/*
8:38 T1 AC
8:52 T2 AC
9:02 T3 AC
9:17 T4 AC

I AK at 9:17.So easy!

I pass the game of surf in only 17.94s!
GOOD!GOOD!

There's too much water in the contest!!!
Let me see see how many students AK the test!
Tang???
I should not sign up the CSP-J account and "donate" 300+ yuan for FCC.
The organization gains too much money but did nothing!
Want to get money?
Join FCC!
China Collecting(money) Foundation


10:23 :
Why not let the contest end?I want to play "Identity V"!
Kong Ju Zhen She?
Lang Xin Si Tie!
Kan'wo shou'fa rong'yu gong'ming!
Yu'nv reng'cha zhi'hou shi yong ji'neng hai'shi ji'neng ne?Hao nan cai a!
Jie'ke shi pu'gong hai'shi pu'gong ne?Hao nan cai a!
Qi'shi zhen hao'wan!

Did the school eat too much s**t?
You let a lot of students of poor score join our Jing'Sai class.
The average of their English scroe even is equal to the worst class of "Zhi Sheng" grade! 
Are they pig?
How did they get into our class?By stupid biology and chemistry Jing'Sai teacher?

*/