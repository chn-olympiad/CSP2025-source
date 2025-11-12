#include<bits/stdc++.h>
using namespace std;
int len;
int num[15];
char s[1000010];
int main(){
  freopen("number.in","r",stdin);	
  freopen("number.out","w",stdout);		
	cin>>s;
	len=strlen(s);
	for (int i=0;i<=len;i++)
	{
		if (s[i]-'0'>=0&&s[i]-'9'<1) num[s[i]-'0']++;
	}
	for (int i=9;i>=0;i--)
	{
		while (num[i]>0)
		{
			cout<<i;
			num[i]--;
		}
	}
	return 0;
}
