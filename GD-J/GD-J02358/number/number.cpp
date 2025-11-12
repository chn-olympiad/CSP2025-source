#include <bits/stdc++.h>
using namespace std;

string s;
int a[100005];

bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	int cnt=0;
	for(int i=1;i<=len;i++)
	{
		if(s[i]>='a'&&s[i]<='z')
		{
			continue;
		}
		else
		{
			cnt++;
			a[cnt]=s[i]+'0';
		}
	}
	
	sort(a+1,a+cnt+1,cmp);
	
	if(len<=2)
	{
		cout<<s;
	}
	return 0;
 } 
