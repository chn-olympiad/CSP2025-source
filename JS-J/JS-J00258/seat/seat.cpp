#include <bits/stdc++.h>
using namespace std;
//CCF is too water.
//T2's fanwei just 10*10=100!
//XD.
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	// Why I can't run it in geany?
	// strange.
	int n,m;
	cin >> n >> m;
	//It's even has no same points! yes! I love CCF!!!
	for(int i = 0;i<n*m;i++)cin>>a[i];
	int rpts=a[0],rmc = 0;
	//It's a numtable(I'm not sure it's called this in English, it's shu biao in Chinese) question.
	//ez
	sort(a,a+n*m);
	for(int i = n*m-1;i>-1;i--)
	{
		if(a[i]==rpts)
		{
			rmc = n*m-i;
			break;
		}
	}// first lie next hang!!
	int l = ceil(rmc*1.0/n),h = l%2?rmc%n:n-rmc%n+1;
	if(h==0)h = l%2?n:h+1;
	cout << l <<" " << h;
	return 0;
}
//09:30 vocal ocean pear(example)2 I couldn't pass
// not that ez
//09:37 2 passed,3wrong.
//Why!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// I'll have a rest. I'll told a story.
// IN this room, we first play the rules.
// but[data deleted] CCF played the rules of GESP
//XD.
// and when I was trying the computer, I find that someone move my delete key to the right key.
// WHy there's People like that in NFLS?
// now, It's NEVER GONNA GIVE YOU UP time!
// int mian()
// int mian()
// int mian()
// int mian()
// int mian()
// int mian()
// int mian()
// int mian()
// int mian()
// freopen()
// freopen()
// freopen()
// freopen()
// freopen()
// freopen()
// freopen()
// freopen()
// freopen()
// froepen()
// froepen()
// froepen()
// froepen()
// froepen()
// freeopen()
// freeopen()
// freeopen()
// freeopen()
// freeopen()
// freeopen()
// freeopen()
// freeopen()
// freeopen()
// freeopen()
// "w",stdin
// "w",stdin
// "w",stdin
// "w",stdin
// "w",stdin
// "w",stdin
// "w",stdin
// "w",stdin
// "w",stdin
// "w",stdin
// "w",stdin
// "w",stdin
// "r",stdout
// "r",stdout
// "r",stdout
// "r",stdout
// "r",stdout
// "r",stdout
// "r",stdout
// "r",stdout
// "r",stdout
// "r",stdout
// "r",stdout
// 09:50 T2 ACed!!!!!!!
//OHHHHHHHHHHHHHH!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//100+100+0+0=200PTS!!!!
// C , I forget to add freopen
// luckly I found it.
