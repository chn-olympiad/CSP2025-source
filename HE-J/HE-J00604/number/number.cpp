#include<bits/stdc++.h>
using  namespace std;
string s;
int sum=0;
int a[1000010]={0};
bool cmp(int x,int y)
{
	return x>=y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0,j=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[j]=s[i]-'0';
			j++;
			sum++;
		}
	}
	sort(a,a+sum,cmp);
	for(int i=0;i<sum;i++)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
