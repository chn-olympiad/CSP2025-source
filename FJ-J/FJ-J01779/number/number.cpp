#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int v[10];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int k=1;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9') v[s[i]-'0']++;;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=v[i];j++)
			putchar(i+'0');
	printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
