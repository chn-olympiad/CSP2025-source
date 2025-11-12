# include <bits/stdc++.h>
using namespace std;
string s;
int num9,num8,num7,num6,num5,num4,num3,num2,num1,num0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    //ios::sync_with_s(false);
    //int x,y;
    //cin >> x>> y;
    //cout << x+y;
    cin >> s;
    for (int i = 0; i< s.size();i++)
    {
		if (s[i] < '0' ||s[i] > '9')continue;
		if (s[i] == '9')num9++;
		else if (s[i] == '8')num8++;
		else if (s[i] == '7')num7++;
		else if (s[i] == '6')num6++;
		else if (s[i] == '5')num5++;
		else if (s[i] == '4')num4++;
		else if (s[i] == '3')num3++;
		else if (s[i] == '2')num2++;
		else if (s[i] == '1')num1++;
		else if (s[i] == '0')num0++;
	}
    
    while(num9--)cout << 9;
    while(num8--)cout << 8;
    while(num7--)cout << 7;
    while(num6--)cout << 6;
    while(num5--)cout << 5;
    while(num4--)cout << 4;
    while(num3--)cout << 3;
    while(num2--)cout << 2;
    while(num1--)cout << 1;
    while(num0--)cout << 0;
	return 0;
}
