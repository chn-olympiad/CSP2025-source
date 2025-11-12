#include<bits/stdc++.h>
using namespace std;
int js0,js1,js2,js3,js4,js5,js6,js7,js8,js9;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin >> s;
	int n = s.size();
	for(int i = 0 ; i < n ; i++)
	{
		if(s[i] == '0')
			js0++;
		else if(s[i] == '1')
			js1++;
		else if(s[i] == '2')
			js2++;
		else if(s[i] == '3')
			js3++;
		else if(s[i] == '4')
			js4++;
		else if(s[i] == '5')
			js5++;
		else if(s[i] == '6')
			js6++;
		else if(s[i] == '7')
			js7++;
		else if(s[i] == '8')
			js8++;
		else if(s[i] == '9')
			js9++;
	}if(js9>0)
	{
		for(int i = 1 ; i <= js9 ; i++)
			cout << 9;
	}
	if(js8>0)
	{
		for(int i = 1 ; i <= js8 ; i++)
			cout << 9;
	}
	if(js7>0)
	{
		for(int i = 1 ; i <= js7 ; i++)
			cout << 7;
	}
	if(js6>0)
	{
		for(int i = 1 ; i <= js6 ; i++)
			cout << 6;
	}
	if(js5>0)
	{
		for(int i = 1 ; i <= js5 ; i++)
			cout << 5;
	}
	if(js4>0)
	{
		for(int i = 1 ; i <= js4 ; i++)
			cout << 4;
	}
	if(js3>0)
	{
		for(int i = 1 ; i <= js3 ; i++)
			cout << 3;
	}
	if(js2>0)
	{
		for(int i = 1 ; i <= js2 ; i++)
			cout << 2;
	}
	if(js1>0)
	{
		for(int i = 1 ; i <= js1 ; i++)
			cout << 1;
	}
	if(js0>0)
	{
		for(int i = 1 ; i <= js0 ; i++)
			cout << 0;
	}
	return 0;
}
