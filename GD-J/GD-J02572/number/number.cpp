#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	int sum=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[i]=s[i];
			sum++;
		}
	}
	int p=s.size();
	sort(a,a+p);
	for(int i=p-1;i>=p-sum;i--)
	{
		cout<<a[i];
	} 
	cout<<endl;
	return 0;
}
