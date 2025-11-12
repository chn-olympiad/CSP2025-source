#include <iostream>

using namespace std;

const int MAXN = 1e6;
int num1 = 0,num2 = 0,num3 = 0,num4 = 0,num5 = 0,num6 = 0,num7 = 0,num8 = 0,num9 = 0,num0 = 0;
char s[MAXN];

int main(void)
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	scanf("%s",s);
	for(int i = 0;s[i] != '\0';i++)
	{
		int now = s[i] - '0';
		if(now == 1)num1++;
		if(now == 2)num2++;
		if(now == 3)num3++;
		if(now == 4)num4++;
		if(now == 5)num5++;
		if(now == 6)num6++;
		if(now == 7)num7++;
		if(now == 8)num8++;
		if(now == 9)num9++;
		if(now == 0)num0++;
	}
	for(int i = 0;i < num9;i++){cout << 9;}
	for(int i = 0;i < num8;i++){cout << 8;}
	for(int i = 0;i < num7;i++){cout << 7;}
	for(int i = 0;i < num6;i++){cout << 6;}
	for(int i = 0;i < num5;i++){cout << 5;}
	for(int i = 0;i < num4;i++){cout << 4;}
	for(int i = 0;i < num3;i++){cout << 3;}
	for(int i = 0;i < num2;i++){cout << 2;}
	for(int i = 0;i < num1;i++){cout << 1;}
	for(int i = 0;i < num0;i++){cout << 0;}
	cout << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}