#include<bits/stdc++.h>
using namespace std;
int cnt[15] = {0};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	char c;
	while(cin>>c)
	if(isdigit(c)) cnt[c-'0']++;
	
	for(int i = 9;i >= 0;i--)
	while(cnt[i])
	{
		putchar(i+'0');
		cnt[i]--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
