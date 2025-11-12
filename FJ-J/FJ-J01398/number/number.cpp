#include<bits/stdc++.h>
#define N 1000010
using namespace std;
char c[N];
int mp[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>c+1;
	int n=strlen(c+1);
	for(int i=1;i<=n;i++)
		if(c[i]>='0'&&c[i]<='9')
			mp[c[i]-'0']++;
	for(int i=9;~i;i--)
		for(int j=1;j<=mp[i];j++)
			cout<<i;
	return 0;
}
