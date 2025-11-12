#include <bits/stdc++.h>
using namespace std;

int a[1000010], cnt;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for(int i = 0; i <=s.size()-1; i++) {
		if(s[i] - '0' <= 9 and s[i] - '0' >= 0) {
			a[++cnt] = s[i]-'0';
			
		}
	}
	sort(a+1, a+cnt+1);
	for(int i = cnt; i>=1; i--) {
		cout << a[i];
	}
	cout <<"\n";
	return 0;
}
//明天星期几
//考试有桔园四中的同学吗
/*
ooooooooooooooooooo                 oo         o
o          o                     oooooooo      o
o     ooooooooooo                     oo   oooooooooo
o     o         o                   oo     o   o    o
o     o ooooooo o                 ooo      o oooooo o
o     o         o               oo  o      o   o    o
o	  ooooooooooo                   oo     oooooooooo
o          o                        ooo        o
o          o                        o oo	   o
o      o   o   o                    o  o       o
o      o o o   o                    o          o
o      o  oo   o                    o          o
*/ 
