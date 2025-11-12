#include<bits/stdc++.h>
using namespace std;
string s;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin >> s;
int len1 = s.size();
for(int i = 0;i <= len1 - 1;i++)
{
	if(s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9' || s[i] == '0')
	{
	cout << s[i];
 	}
 	else  cout << "";
}
fclose(stdin);
fclose(stdout);
return 0;
}
