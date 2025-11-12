#include<iostream> 
using namespace std;
int x[100005] , n , k , ans = 0;
bool fg[100005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> x[i];
		x[i] ^= x[i - 1];
	}
	int enf = 0;
	for(int i = 1;i <= n;i++)
	{
		if((x[i] ^ x[i - 1]) == k)
		{
			ans++;
			fg[i] = 1;
			continue ;
		}
		for(int j = i;j >= 1;j--)
		{
			if(fg[j])
				break;
			if((x[j - 1] ^ x[i]) == k)
			{
				for(int kk = j;kk <= i;kk++)
					fg[kk] = 1;
				ans++;	
				enf = i;
				break;		
			}
		}
	}
	cout << ans;
	return 0;
}
/*
int int long long bis/stdc++.h iostream using namespace std std std main
return reureruueb retubnr reurb eurb e loce oi OIer 
OIwiki
I love CCF !
I AK IOI ! 
10:30 48pts!!!
big test is AC!!!

10:35
use ton is 100pts ?
10:40
#include<iostream> 
using namespace std;
int x[100005] , n , k , ans = 0;
bool fg[100005];
int chu[1048580][3];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> x[i];
		x[i] ^= x[i - 1];
		chu[x[i]][0] = i;
		chu[x[i]][0] = 
	}
	bool zd = 0;
	int enf = 0;
	for(int i = 1;i <= n;i++)
	{
		zd = 0;
		if((x[i] ^ x[i - 1]) == k)
		{
			ans++;
			zd = 1, fg[i] = 1;
			continue ;
		}
		for(int j = i;j >= 1;j--)
		{
			if(fg[j])
				break;
			if((x[j - 1] ^ x[i]) == k)
			{
				zd = 1;
				for(int kk = j;kk <= i;kk++)
					fg[kk] = 1;
				ans++;	
				enf = i;
				break;		
			}
		}
	}
	cout << ans;
	return 0;
}
make that will use lianbiao , it's a lots of xijie
let's see T4
10:48
Why am I feel T3 can't get to 48 pts;
RP++
I must see T4 now;
11:22
maybe I can use VECTOR it's easy;
but now let me test in NOI linux2
OH , I can't open the out file
it's too big
I check it in windows
Oh I fell I have not full time to write T3
But get I can get pts is the first.
Maybe I can't get YIDENG
BUT I am 13 years old.
It is a long way to me;
my English is so bad.
my luogu ID is Manacher
I'm in the SSSY shool.
I must go to chek now.
11:34
11:41
WHY I need to write my information?
*/
