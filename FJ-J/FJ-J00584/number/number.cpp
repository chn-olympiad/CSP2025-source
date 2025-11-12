#include<bits/stdc++.h>
using namespace std;
long long num[11];
char r;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>r)
	{
		if(int(r)-int('0')>=0&&int(r)-int('0')<=9)
		num[int(r)-int('0')]++;
	}
	for(int i=9;i>=0;--i)
	while(num[i])
	{
		printf("%d",i);
		num[i]--;
	}
	return 0;
}
