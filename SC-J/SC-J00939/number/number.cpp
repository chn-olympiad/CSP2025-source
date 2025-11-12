#include<bits/stdc++.h>
using namespace std;
char a;
long long b[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>a)
	{
		if(a-'0'>=0&&a-'0'<=9)	b[a-'0']++;
	}
	for(int i=9;i>=0;i--)
		for(int j=1;j<=b[i];j++)
			cout<<i;
	return 0;
}