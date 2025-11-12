#include<bits/stdc++.h>
using namespace std;
int pd,bj[110];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;++i)
	{
		if(s[i]>='0'&&s[i]<='9') bj[int(s[i]-'0')]++;
	}
	for(int i=9;i>=0;--i)
	{
		for(int j=1;j<=bj[i];++j)
		{
			printf("%d",i);
		}
	}
	return 0;
}
