#include<bits/stdc++.h>
using namespace std;
char c[1000010];
int sum[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>c;
	for(int i=0;i<strlen(c);i++)
	{
		if(c[i]>='0'&&c[i]<='9') sum[c[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		while(sum[i]!=0)
		{
			cout<<i;
			sum[i]--;
		}
	}
}
