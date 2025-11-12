#include<bits/stdc++.h>

using namespace std;

long long a[1000001];
long long fg(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long cnt=1;
	for(long long i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			//cout<<int(s[i])-48<<" ";
			a[cnt]=int(s[i])-48;
			cnt++;
		}
	}
	sort(a+1,a+cnt+1,fg);
	for(long long i=1;i<cnt;i++)
		cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
