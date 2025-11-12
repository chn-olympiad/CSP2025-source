#include<bits/stdc++.h>
using namespace std;
long long a[1000010],k=1;
string s;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[k]=s[i]-'0';
			k++;
		}
	}
	sort(a+1,a+k,cmp);
	for(int i=1;i<k;i++)
	{
		cout<<a[i];
	}
	return 0;
}