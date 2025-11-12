#include<bits/stdc++.h>
using namespace std;

//bool f(char a)
//{
//	if(a >= '0' && a <= '9')
//	{
//		return true;
//		return 0;
//	}
//}
const int N = 1e6+5;
string s;
long long a[N],t,b[N];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<s.size();i++)
	{
//		if(f(s[i]))
//		{
			if(s[i] >= 'a' && s[i] <= 'z')
			{
				continue;
			}
			else if(s[i] == '0')
			{
				a[i] += 0;
				t++;
			}
			else if(s[i] == '1')
			{
				a[i] += 1;
				t++;
			}
			else if(s[i] == '2')
			{
				a[i] += 2;
				t++;
			}
			else if(s[i] == '3')
			{
				a[i] += 3;
				t++;
			}
			else if(s[i] == '4')
			{
				a[i] += 4;
				t++;
			}
			else if(s[i] == '5')
			{
				a[i] += 5;
				t++;
			}
			else if(s[i] == '6')
			{
				a[i] += 6;
				t++;
			}
			else if(s[i] == '7')
			{
				a[i] += 7;
				t++;
			}
			else if(s[i] == '8')
			{
				a[i] += 8;
				t++;
			}
			else
			{
				a[i] += 9;
				t++;
			}
//			a[i] += s[i];
//		}
//		cout << a[i];
//		if(a[i] >= '1' && a[i] <= '9')
//		{
//			a[i]+=s;
//			t++;
//		}
//		else
//		{
//			continue;
//		}
	}
	sort(a,a+t+1);
	for(int i=t;i>=1;i--)
	{
		cout << a[i];
	}
	return 0;
}
