#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;

char s[N];
int v[N];
int num[10];
int n=1, m=0;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	memset(num, 0, sizeof(num));
	bool flag=1;
	scanf("%s", s+1);
	while(s[n]) n++;
	n--;
	for(int i=1;i<=n;i++)
	{
		if((s[i]-'0')>=0&&(s[i]-'0')<=9)
		{
			v[++m] = s[i]-'0';
			num[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(i==0&&flag)
		{
			printf("0");
			return 0;
		}
		if(num[i]){
			flag=false;
			while(num[i]--)printf("%d", i);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
