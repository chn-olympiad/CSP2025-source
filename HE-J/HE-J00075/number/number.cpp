#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
int b=0,flag=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0; i<=n; i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			b++;
			a[b]=s[i]-'0';
			if(a[b]!=0)
			{
				flag=1;
			}
		}
	} 
	sort(a+1,a+b+1);
	if(flag==0)
	{
		cout<<"0";
		return 0;
	}
	for(int i=b; i>=1; i--)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
