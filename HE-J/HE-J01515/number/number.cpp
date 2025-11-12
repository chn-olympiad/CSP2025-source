#include<bits/stdc++.h>
using namespace std;
string s;
int a[100005],sum;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[i]=s[i]-'0';
			sum++;
		}
	}
	sort(a,a+n,cmp);
	if(a[0]==0)
	{
		cout<<0;
	}
	else 
	{
		for(int i=0;i<sum;i++)
		{
			cout<<a[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 


