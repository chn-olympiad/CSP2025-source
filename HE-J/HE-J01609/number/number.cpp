#include<bits/stdc++.h>
using namespace std;
const int M = 1000010;
string s;
int a[M], b[M];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0;i <= M; i++)
		a[i] = -1;
	for(int i = 0; i < s.length(); i++)
	{
		
		if(s[i] == '0')a[i] = 0; 
		if(s[i]  == '1')a[i] = 1;
		if(s[i] == '2')a[i] = 2;
		if(s[i] == '3')a[i] = 3;
		if(s[i] == '4')a[i] = 4;
		if(s[i] == '5')a[i] = 5;
		if(s[i] == '6')a[i] = 6;
		if(s[i] == '7')a[i] = 7;
		if(s[i] == '8')a[i] = 8;
		if(s[i] == '9')a[i] = 9;
	}
	int l = 1;
	for(int i = 0; i <= M; i++)
	{
		if(a[i] != -1)
		{
			b[l] = a[i];
			l++;
		}
	}
	sort(b, b + l);
	for(int i = l - 1; i >= 1; i--)
	cout << b[i];
	cout << endl;
	return 0;	
} 
