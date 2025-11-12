#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int number_cin[N];
string s;

/*
BF:
有字符串S,S只有小写英文字母+数字(1~9中必有一个)；
在S中提取出数字，再排列数字，构成一个最大值 
*/

int main()
{
	ios::sync_with_stdio(),cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int lenth = s.size();
	for(int i = lenth;i >= 1;i--) s[i] = s[i - 1]; //将S从0-N转换到1-n
	//0ASCll : 48,9ASCll : 57
	//提取数字 
	int math_cnt = 0; 
	for(int i = 1;i <= lenth;i++)
	{
		if(int(s[i]) >= 48 && int(s[i]) <= 57) //s[i]为数字
		{
			math_cnt++;
			number_cin[math_cnt] = int(s[i]) - 48;
		}
	}
	sort(number_cin + 1,number_cin + math_cnt + 1);
	for(int i = math_cnt;i >= 1;i--) cout << number_cin[i];
	return 0;
}