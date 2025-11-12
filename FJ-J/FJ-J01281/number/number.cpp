#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[10];
	for(int i = 0;i<10;i++)
	{
		a[i] = i;
	}
	int T[1000];
	string s;
	cin>>s;
	int N = 0;
	for(int i = 0;i<s.size();i++)
	{
		if(s[i] == '1') 
		{
			T[N] = 1;
			N++;
		}
		if(s[i] == '2') 
		{
			T[N] = 2;
			N++;
		}
		if(s[i] == '3') 
		{
			T[N] = 3;
			N++;
		}
		if(s[i] == '4') 
		{
			T[N] = 4;
			N++;
		}
		if(s[i] == '5') 
		{
			T[N] = 5;
			N++;
		}
		if(s[i] == '6') 
		{
			T[N] = 6;
			N++;
		}
		if(s[i] == '7') 
		{
			T[N] = 7;
			N++;
		}
		if(s[i] == '8') 
		{
			T[N] = 8;
			N++;
		}
		if(s[i] == '9') 
		{
			T[N] = 9;
			N++;
		}
		if(s[i] == '0') 
		{
			T[N] = 0;
			N++;
		}
	} 
	sort(T,T+N);
	for(int i = N-1;i>=0;i--)
	{
		cout<<T[i];
	}
	fclose(stdin);
	fclose(stdout);
}
